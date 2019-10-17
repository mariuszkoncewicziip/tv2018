#include <Bounce2.h>
#include "Keyboard.h"

#define B1 2
#define B2 4

// Inicjalizacja obiektusssssss Bounce
Bounce debouncer1 = Bounce(); 
Bounce debouncer2 = Bounce(); 

int v1, v2;
int u1 = false, u2 = false;

void setup() {
  Keyboard.begin();
  Serial.begin(9600);
  Serial.println("Sterownik klawiatury Arduino Leonardo");
  Serial.println("BUTTON 1 PIN 2");
  Serial.println("BUTTON 2 PIN 4");

  // Konfiguracja pinu przycisku i aktywowanie rezystora podciągającego:
  pinMode(B1,INPUT_PULLUP);
  pinMode(B2,INPUT_PULLUP);

  // Po konfiguracji przycisku, ustawienie działania funkcji Bounce :
  debouncer1.attach(B1);
  debouncer1.interval(10); // interwał w ms
  debouncer2.attach(B2);
  debouncer2.interval(10); // interwał w ms
}

void loop() {
  // BACK()
  debouncer1.update();
  // Odczyt zaktualizowanej wartości (v1) :
  v1 = debouncer1.read();
  if (v1 == LOW && u1) { 
    Serial.println("a");
    Keyboard.print("a"); 
    u1 = false;
  }
  if (v1 == HIGH) u1 = true;

  // FORWARD()
  debouncer2.update();
  // Odczyt zaktualizowanej wartości (v2) :
  v2 = debouncer2.read();
  if (v2 == LOW && u2) { 
    Serial.println("s");
    Keyboard.print("s"); 
    u2 = false;
  }
  if (v2 == HIGH) u2 = true;


}
