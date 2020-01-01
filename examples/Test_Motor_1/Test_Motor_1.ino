#include "cle_thunderborg.h"
//ThunderBorg TBC1(4, 3, 2);  //Pins: red =4, green =3, blue =2
//ThunderBorg TBC1 = ThunderBorg(4, 3, 2); 
ThunderBorg TBC1;


void setup() {}

void loop() {
	TBC1.SetMotor1FWD(50);
	delay(500);
	TBC1.SetMotor1FWD(100);
	delay(500);
	TBC1.SetMotor1FWD(150);
	delay(500);
	TBC1.SetMotor1FWD(200);
	delay(500);
	TBC1.SetMotor1FWD(255);
	delay(2000);
	TBC1.SetMotor1FWD(150);
	delay(1000);
	TBC1.SetMotor1FWD(80);
	delay(1000);
	
	TBC1.SetMotor1REV(50);
	delay(500);
	TBC1.SetMotor1REV(100);
	delay(500);
	TBC1.SetMotor1REV(150);
	delay(500);
	TBC1.SetMotor1REV(200);
	delay(500);
	TBC1.SetMotor1REV(255);
	delay(2000);
	TBC1.SetMotor1REV(150);
	delay(1000);
	TBC1.SetMotor1REV(80);
	delay(1000);	
	
	
	
	

}