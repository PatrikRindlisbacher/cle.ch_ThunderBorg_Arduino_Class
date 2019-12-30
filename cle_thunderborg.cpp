#include "cle_thunderborg.h"

RGBLed::RGBLed (byte redPin, byte greenPin, byte bluePin) {
	this->redPin   = redPin;
	this->greenPin = greenPin;
	this->bluePin  = bluePin;
}

void RGBLed::setRGB(byte r, byte g, byte b) {
	Wire.begin();
	Wire.beginTransmission(0x15); // transmit to device 
	Wire.write(1);              // sends one byte
	Wire.write(r);              // sends one byte
	Wire.write(g);              // sends one byte
	Wire.write(b);              // sends one byte
	Wire.endTransmission();    // stop transmitting

}

void RGBLed::blink(char color, byte times, unsigned int ms) {
	byte r=0, g=0, b=0;
	if(color == 'r')      r = 255;
	else if(color == 'g') g = 255;
	else if(color == 'b') b = 255;
	else return ;

	for (byte i = 0; i < times; i++) {
		setRGB(r, g, b);
		delay(ms);
		setRGB(0, 0, 0);
		delay(ms);
	}
}

void RGBLed::SetLed1(byte XXX, byte r, byte g, byte b){
	Wire.begin();
	Wire.beginTransmission(0x15); // transmit to device 
	Wire.write(1);              // sends one byte
	Wire.write(r);              // sends one byte
	Wire.write(g);              // sends one byte
	Wire.write(b);              // sends one byte
	Wire.endTransmission();    // stop transmitting
}