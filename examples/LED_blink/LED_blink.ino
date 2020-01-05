#include "cle_thunderborg.h"

ThunderBorg TBC1;


void setup() {}

void loop() {
  TBC1.SetLedShowBattery(false);
  TBC1.SetLed1(100,0,0);
  delay(500);
  TBC1.SetLed1(0,100,0);
  delay(500);
    TBC1.SetLed1(0,0,100);
  delay(500);
  

}
