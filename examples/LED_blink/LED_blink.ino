#include "cle_thunderborg.h"
RGBLed rgb(4, 3, 2);  //Pins: red =4, green =3, blue =2

void setup() {}

void loop() {
  rgb.setRGB(1, 50 , 1);
  delay(500);
  rgb.setRGB(100, 5 , 1);
  delay(500);
  

}
