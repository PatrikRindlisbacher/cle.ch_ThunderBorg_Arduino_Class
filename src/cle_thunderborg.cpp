#include "cle_thunderborg.h"

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
	SendCommand(COMMAND_SET_LED1,3,r,g,b);
}

void ThunderBorg::SetMotor1FWD(byte power){
	SendCommand(COMMAND_SET_M1_FWD,1,power,0,0);
}

void ThunderBorg::SetMotor1REV(byte power){
	SendCommand(COMMAND_SET_M1_REV,1,power,0,0);
}

void ThunderBorg::SetMotor2FWD(byte power){
	SendCommand(COMMAND_SET_M2_FWD,1,power,0,0);
}
void ThunderBorg::SetMotor2REV(byte power){
	SendCommand(COMMAND_SET_M2_FWD,1,power,0,0);

}

void ThunderBorg::SendCommand(byte Command, byte number_of_Values, byte Value1, byte Value2, byte Value3){
	Wire.begin();
	Wire.beginTransmission(I2C_ID_THUNDERBORG);				// begin transmit to device 
	Wire.write(Command);									// sends Command byte
	if (number_of_Values >=1 ) {Wire.write(Value1);}		// sends one byte Value 1
	if (number_of_Values >=2 ) {Wire.write(Value2);}		// sends one byte Value 2
	if (number_of_Values >=3 ) {Wire.write(Value3);}		// sends one byte Value 3
	Wire.endTransmission();						// stop transmitting	
}