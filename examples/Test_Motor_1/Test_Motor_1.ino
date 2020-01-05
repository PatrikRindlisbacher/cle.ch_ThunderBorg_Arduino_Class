#include "cle_thunderborg.h"
ThunderBorg TBC1;							// Klasse initialisieren als TBC1 

// Anregungen gerne im Github als Fragen (issues) oder per Mail an pr@cle.ch


void setup() {
	TBC1.Init(0x15);						// Intit Thunderborg
}

void loop() {
	TBC1.SetMotor1FWD(50);					// Motor 1 vorwärts
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
	
	TBC1.SetMotor1REV(50);					// Motor 1 rückwärts
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