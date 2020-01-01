#include "cle_thunderborg.h"
//ThunderBorg TBC1(4, 3, 2);  //Pins: red =4, green =3, blue =2
//ThunderBorg TBC1 = ThunderBorg(4, 3, 2); 
ThunderBorg TBC1;


void setup() {}

void loop() {
  TBC1.SetMotor1(50);
  delay(500);
  TBC1.SetMotor1(100);
  delay(500);
    TBC1.SetMotor1(0);
  delay(500);
  

}