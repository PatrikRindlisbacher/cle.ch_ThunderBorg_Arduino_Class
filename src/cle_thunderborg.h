#ifndef __Thunder_Borg__
#define __Thunder_Borg__

#include <Arduino.h>
#include <Wire.h>

// Constant Commands
const byte COMMAND_SET_LED1				= 1;		// Set the colour of the ThunderBorg LED
//const byte COMMAND_GET_LED1				= 2;		// Get the colour of the ThunderBorg LED
const byte COMMAND_SET_LED2				= 3;		// Set the colour of the ThunderBorg Lid LED
//const byte COMMAND_GET_LED2				= 4;		// Get the colour of the ThunderBorg Lid LED
//const byte COMMAND_SET_LEDS				= 5;		// Set the colour of both the LEDs
const byte COMMAND_SET_LED_BATT_MON		= 6;		// Set the colour of both LEDs to show the current battery level
//const byte COMMAND_GET_LED_BATT_MON		= 7;		// Get the state of showing the current battery level via the LEDs
const byte COMMAND_SET_M1_FWD			= 8;		// Set motor A PWM rate in a forwards direction
const byte COMMAND_SET_M1_REV			= 9;		// Set motor A PWM rate in a reverse direction
//const byte COMMAND_GET_M1				= 10;		// Get motor A direction and PWM rate
const byte COMMAND_SET_M2_FWD			= 11;		// Set motor B PWM rate in a forwards direction
const byte COMMAND_SET_M2_REV			= 12;		// Set motor B PWM rate in a reverse direction
//const byte COMMAND_GET_M2				= 13;		// Get motor B direction and PWM rate
const byte COMMAND_ALL_OFF				= 14;		// Switch everything off
//const byte COMMAND_GET_DRIVE_A_FAULT	= 15;		// Get the drive fault flag for motor A, indicates faults such as short-circuits and under voltage
//const byte COMMAND_GET_DRIVE_B_FAULT	= 16;		// Get the drive fault flag for motor B, indicates faults such as short-circuits and under voltage
//const byte COMMAND_SET_ALL_FWD			= 17;		// Set all motors PWM rate in a forwards direction
//const byte COMMAND_SET_ALL_REV			= 18;		// Set all motors PWM rate in a reverse direction
//const byte COMMAND_SET_FAILSAFE			= 19;		// Set the failsafe flag, turns the motors off if communication is interrupted
//const byte COMMAND_GET_FAILSAFE			= 20;		// Get the failsafe flag
//const byte COMMAND_GET_BATT_VOLT		= 21;		// Get the battery voltage reading
const byte COMMAND_SET_BATT_LIMITS		= 22;		// Set the battery monitoring limits
//const byte COMMAND_GET_BATT_LIMITS		= 23;		// Get the battery monitoring limits
//const byte COMMAND_WRITE_EXTERNAL_LED	= 24;		// Write a 32bit pattern out to SK9822 / APA102C

// Constant values
const int I2C_SLAVE						= 0x0703;	// 
const float VOLTAGE_PIN_MAX				= 36.3;		// Maximum voltage from the analog voltage monitoring pin
//const float VOLTAGE_PIN_CORRECTION		= 0.0;		// Correction value for the analog voltage monitoring pin
const float BATTERY_MIN_DEFAULT			= 7.0;		// Default minimum battery monitoring voltage
const float BATTERY_MAX_DEFAULT			= 35.0;		// Default maximum battery monitoring voltage
const byte I2C_ID_THUNDERBORG			= 0x15;		// Standard I2C Adresse vom Thunderborg Board
const byte COMMAND_GET_ID				= 0x99;		// Get the board identifier
const byte COMMAND_SET_I2C_ADD			= 0xAA;		// Set a new I2C address
const byte COMMAND_VALUE_FWD			= 1;		// I2C value representing forward
const byte COMMAND_VALUE_REV			= 2;		// I2C value representing reverse
const byte COMMAND_VALUE_ON				= 1;		// I2C value representing on
const byte COMMAND_VALUE_OFF			= 0;		// I2C value representing off
const int COMMAND_ANALOG_MAX			= 0x3FF;	// Maximum value for analog readings
const byte PWM_MAX						= 255;		// Maximum Wert für PWM

class ThunderBorg {
private:
	byte I2C_ID_THUNDERBORG_Current;				// Current I2C Adresse
	//byte I2C_Buffer[];
	byte LED_Level_Battery_State_Min;				// Minimum Level for LED Battery_State --> Color RED
	byte LED_Level_Battery_State_Max;				// Maximum Level for LED Battery_State --> Color Green
	void I2C_send_Buffer();
	void SendCommand(byte Command, byte number_of_Values, byte Value1, byte Value2, byte Value3);
public:
	void Init(byte I2C_Adress);
	//void SetNewAddress(I2C *i2c, uint8_t newAddress);
	void SetLedShowBattery(bool state, float SET_BATTERY_MIN = BATTERY_MIN_DEFAULT , float SET_BATTERY_Max = BATTERY_MAX_DEFAULT);
	void SetLed1(byte r, byte g, byte b);
	void SetMotors(int M1_Power, int M2_Power);
	void SetMotor1FWD(byte power);
	void SetMotor1REV(byte power);
	//float GetMotor1(I2C *i2c);
	void SetMotor2FWD(byte power);
	void SetMotor2REV(byte power);
	//float GetMotor2(I2C *i2c);
	//float GetBatteryReading(I2C *i2c);
};
#endif