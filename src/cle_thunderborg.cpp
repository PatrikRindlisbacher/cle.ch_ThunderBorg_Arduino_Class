#include "cle_thunderborg.h"

void ThunderBorg::setRGB(byte r, byte g, byte b) {
	Wire.begin();
	Wire.beginTransmission(I2C_ID_THUNDERBORG);		// transmit to device 
	Wire.write(COMMAND_SET_LED1);					// sends one byte
	Wire.write(r);									// sends one byte
	Wire.write(g);									// sends one byte
	Wire.write(b);									// sends one byte
	Wire.endTransmission();							// stop transmitting

}

void ThunderBorg::blink(char color, byte times, unsigned int ms) {
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

void ThunderBorg::SetLedShowBattery(bool state) {
	Wire.begin();
	Wire.beginTransmission(I2C_ID_THUNDERBORG); // transmit to device 
	if (state == true) {
		Wire.write(COMMAND_SET_LED_BATT_MON);		// sends one byte
		Wire.write(COMMAND_VALUE_ON);				// sends one byte
	}
	else {
		Wire.write(COMMAND_SET_LED_BATT_MON);		// sends one byte
		Wire.write(COMMAND_VALUE_OFF);				// sends one byte
	}
	Wire.endTransmission();						// stop transmitting
}

void ThunderBorg::SetLed1(byte r, byte g, byte b){
	Wire.begin();
	Wire.beginTransmission(I2C_ID_THUNDERBORG); // transmit to device 
	Wire.write(COMMAND_SET_LED1);				// sends one byte
	Wire.write(r);								// sends one byte
	Wire.write(g);								// sends one byte
	Wire.write(b);								// sends one byte
	Wire.endTransmission();						// stop transmitting
}

void ThunderBorg::SetMotor1FWD(byte power){
	Wire.begin();
	Wire.beginTransmission(I2C_ID_THUNDERBORG);	// transmit to device 
	Wire.write(COMMAND_SET_M1_FWD);				// sends one byte
	Wire.write(power);							// sends one byte
	Wire.endTransmission();						// stop transmitting	
}

void ThunderBorg::SetMotor1REV(byte power){
	Wire.begin();
	Wire.beginTransmission(I2C_ID_THUNDERBORG);	// transmit to device 
	Wire.write(COMMAND_SET_M1_REV);				// sends one byte
	Wire.write(power);							// sends one byte
	Wire.endTransmission();						// stop transmitting	
}

void ThunderBorg::SetMotor2FWD(byte power){
	Wire.begin();
	Wire.beginTransmission(I2C_ID_THUNDERBORG);	// transmit to device 
	Wire.write(COMMAND_SET_M2_FWD);				// sends one byte
	Wire.write(power);							// sends one byte
	Wire.endTransmission();						// stop transmitting	
}
void ThunderBorg::SetMotor2REV(byte power){
	Wire.begin();
	Wire.beginTransmission(I2C_ID_THUNDERBORG);	// transmit to device 
	Wire.write(COMMAND_SET_M2_REV);				// sends one byte
	Wire.write(power);							// sends one byte
	Wire.endTransmission();						// stop transmitting	
}