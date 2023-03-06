/*
 * EEPROM Clear
 *
 * Sets all of the bytes of the EEPROM to 0.
 * Please see eeprom_iteration for a more in depth
 * look at how to traverse the EEPROM.
 *
 * This example code is in the public domain.
 */

#include <EEPROM.h>

int zahl;
int maxTemperatur;
int minTemperatur;
int summe;
int mittelWert;

void setup() {
  // initialize the LED pin as an output.
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  minTemperatur = 255;
  /***
    Iterate through each byte of the EEPROM storage.

    Larger AVR processors have larger EEPROM sizes, E.g:
    - Arduno Duemilanove: 512b EEPROM storage.
    - Arduino Uno:        1kb EEPROM storage.
    - Arduino Mega:       4kb EEPROM storage.

    Rather than hard-coding the length, you should use the pre-provided length function.
    This will make your code portable to all AVR processors.
  ***/

  for (int i = 0 ; i < EEPROM.length() ; i++) {
    EEPROM.write(i, random(225));
  }

  // turn the LED on when we're done
  digitalWrite(13, HIGH);
  delay(1000);
  for (int i = 0; i < EEPROM.length(); i++){
      zahl = EEPROM.read(i);
      Serial.print(i);
      Serial.print(" temperatur: ");
      Serial.println(zahl);
      Serial.print(" | ");
      
  if(maxTemperatur < zahl){
     maxTemperatur = zahl;
    }
  if(minTemperatur > zahl){
      minTemperatur = zahl;
    }
    Serial.print("maximale Temperatur: "); 
    Serial.print(maxTemperatur);
    Serial.print(" | "); 
    Serial.print("minimale Temperatur: "); 
    Serial.print(minTemperatur);
    Serial.print(" | "); 

    Serial.print ("Summme: ");
    summe = maxTemperatur + minTemperatur;
    Serial.print(summe);
    Serial.print(" | "); 
    Serial.print ("Durchschnittstemperatur: ");
    mittelWert = summe / 2;
    Serial.println(mittelWert);
  }
  digitalWrite(13, LOW);
}

void loop() {
}
