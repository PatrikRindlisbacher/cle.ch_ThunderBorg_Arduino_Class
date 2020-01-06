#include "cle_thunderborg.h"
ThunderBorg TBC1;							// Klasse initialisieren als TBC1 

// Anregungen gerne im Github als Fragen (issues) oder per Mail an pr@cle.ch


void setup() {
	TBC1.Init(0x15);						// Intit Thunderborg
}

void loop() {
	TBC1.SetMotors(75,75);					// Motor 1 Forward Power 75 / Motor 2 Forward Power 75
	delay(1000);
	TBC1.SetMotors(255,255);				// Motor 1 Forward Power 255 / Motor 2 Forward Power 255
	delay(1000);
	TBC1.SetMotors(0,0);					// Motor 1  Stopp / Motor 2 Stopp
	delay(1500);
	TBC1.SetMotors(-75,-75);				// Motor 1 Forward Power 75 / Motor 2 Forward Power 75
	delay(1000);
	TBC1.SetMotors(-255,-255);				// Motor 1 Forward Power 255 / Motor 2 Forward Power 255
	delay(1000);
	TBC1.SetMotors(0,0);					// Motor 1  Stopp / Motor 2 Stopp
	delay(1500);
}