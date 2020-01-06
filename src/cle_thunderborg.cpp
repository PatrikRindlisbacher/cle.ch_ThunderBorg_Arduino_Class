#include "cle_thunderborg.h"

void ThunderBorg::Init(byte I2C_Adress) {
	I2C_ID_THUNDERBORG_Current = I2C_Adress;							// notice I2C_Adress
	SendCommand(COMMAND_SET_LED_BATT_MON,1,COMMAND_VALUE_ON,0,0);		// LED Battery Status ON
	SendCommand(COMMAND_ALL_OFF,0,0,0,0);								// All Motors Stop
}

void ThunderBorg::SetLedShowBattery(bool state, float SET_BATTERY_MIN = BATTERY_MIN_DEFAULT , float SET_BATTERY_Max = BATTERY_MAX_DEFAULT) {
	if (state == true) {
		SendCommand(COMMAND_SET_LED_BATT_MON,1,COMMAND_VALUE_ON,0,0);
		

        LED_Level_Battery_State_Min = 255 * (SET_BATTERY_MIN / float(VOLTAGE_PIN_MAX));
        LED_Level_Battery_State_Max = 255 * (SET_BATTERY_Max / float(VOLTAGE_PIN_MAX));
        //LED_Level_Battery_State_Min = byte(LED_Level_Battery_State_Min * 0xFF);
        //LED_Level_Battery_State_Max = byte(LED_Level_Battery_State_Max * 0xFF);
		//LED_Level_Battery_State_Min = 50;
		//LED_Level_Battery_State_Max = 72;
		SendCommand(COMMAND_SET_BATT_LIMITS,2,LED_Level_Battery_State_Min,LED_Level_Battery_State_Max,0);
		}
	else {
		SendCommand(COMMAND_SET_LED_BATT_MON,1,COMMAND_VALUE_OFF,0,0);
	}
}

void ThunderBorg::SetLed1(byte r, byte g, byte b){
	SendCommand(COMMAND_SET_LED1,3,r,g,b);								// SET LED RGB
}

void ThunderBorg::SetMotors(int M1_Power, int M2_Power){
	if (M1_Power==0 and M1_Power==0){SendCommand(COMMAND_ALL_OFF,0,0,0,0);}
	if (M1_Power>0 ){SetMotor1FWD(byte(M1_Power));}	
	if (M2_Power>0 ){SetMotor2FWD(byte(M2_Power));}	
	if (M1_Power<0 ){SetMotor1REV(byte(M1_Power*-1));}	
	if (M2_Power<0 ){SetMotor2REV(byte(M2_Power*-1));}	
}


void ThunderBorg::SetMotor1FWD(byte power){
	SendCommand(COMMAND_SET_M1_FWD,1,power,0,0);						// Motor 1 Forward Power
}

void ThunderBorg::SetMotor1REV(byte power){
	SendCommand(COMMAND_SET_M1_REV,1,power,0,0);						// Motor 1 Reverse Power
}

void ThunderBorg::SetMotor2FWD(byte power){
	SendCommand(COMMAND_SET_M2_FWD,1,power,0,0);						// Motor 2 Forward Power
}
void ThunderBorg::SetMotor2REV(byte power){
	SendCommand(COMMAND_SET_M2_FWD,1,power,0,0);						// Motor 2 Reverse Power
}

void ThunderBorg::SendCommand(byte Command, byte number_of_Values, byte Value1, byte Value2, byte Value3){
	Wire.begin();
	Wire.beginTransmission(I2C_ID_THUNDERBORG_Current);	    			// begin transmit to device 
	Wire.write(Command);												// sends Command byte
	if (number_of_Values >=1 ) {Wire.write(Value1);}					// sends one byte Value 1
	if (number_of_Values >=2 ) {Wire.write(Value2);}					// sends one byte Value 2
	if (number_of_Values >=3 ) {Wire.write(Value3);}					// sends one byte Value 3
	Wire.endTransmission();												// stop transmitting	
}