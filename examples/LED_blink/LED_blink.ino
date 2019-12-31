#include "cle_thunderborg.h"
//ThunderBorg TBB1(4, 3, 2);  //Pins: red =4, green =3, blue =2
//ThunderBorg TBB1 = ThunderBorg(4, 3, 2); 
ThunderBorg TBB1;


void setup() {}

void loop() {
  TBB1.setRGB(1, 50 , 1);
  delay(500);
  TBB1.setRGB(100, 5 , 1);
  delay(500);
  

}
