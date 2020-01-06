// The colours shown range from full red at minimum or below, yellow half way, and full green at maximum or higher.
// LED Battery Status Full=green --> Medium=yellow --> Empty=red

#include "cle_thunderborg.h"

ThunderBorg TBC1;

void setup() {
	TBC1.Init(0x15);						 // Intit Thunderborg
  TBC1.SetLedShowBattery(true,9.9,12.2);    // Example LED Battery Status  3S Lipo      MIN 3 x 3.3V = 9.9V      MAX 3 x 4.2V = 12.6V
}

void loop() {
  
}