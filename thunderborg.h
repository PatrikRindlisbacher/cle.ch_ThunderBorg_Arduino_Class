#ifndef THUNDERBORG_H
#define THUNDERBORG_H

#include <Wire.h>

class RGBLed {
public:

	// Constant values
	extern int I2C_SLAVE;
	extern uint8_t PWM_MAX;
	extern uint8_t I2C_MAX_LEN;
	extern float VOLTAGE_PIN_MAX;  // Maximum voltage from the analog voltage monitoring pin
	extern float VOLTAGE_PIN_CORRECTION;   // Correction value for the analog voltage monitoring pin
	extern float BATTERY_MIN_DEFAULT;   // Default minimum battery monitoring voltage
	extern float BATTERY_MAX_DEFAULT;  // Default maximum battery monitoring voltage

	extern uint8_t I2C_ID_THUNDERBORG;

	extern uint8_t COMMAND_SET_LED1;     // Set the colour of the ThunderBorg LED
	extern uint8_t COMMAND_GET_LED1;     // Get the colour of the ThunderBorg LED
	extern uint8_t COMMAND_SET_LED2;     // Set the colour of the ThunderBorg Lid LED
	extern uint8_t COMMAND_GET_LED2;     // Get the colour of the ThunderBorg Lid LED
	extern uint8_t COMMAND_SET_LEDS;     // Set the colour of both the LEDs
	extern uint8_t COMMAND_SET_LED_BATT_MON;     // Set the colour of both LEDs to show the current battery level
	extern uint8_t COMMAND_GET_LED_BATT_MON;     // Get the state of showing the current battery level via the LEDs
	extern uint8_t COMMAND_SET_A_FWD;     // Set motor A PWM rate in a forwards direction
	extern uint8_t COMMAND_SET_A_REV;     // Set motor A PWM rate in a reverse direction
	extern uint8_t COMMAND_GET_A;    // Get motor A direction and PWM rate
	extern uint8_t COMMAND_SET_B_FWD;    // Set motor B PWM rate in a forwards direction
	extern uint8_t COMMAND_SET_B_REV;    // Set motor B PWM rate in a reverse direction
	extern uint8_t COMMAND_GET_B;    // Get motor B direction and PWM rate
	extern uint8_t COMMAND_ALL_OFF;    // Switch everything off
	extern uint8_t COMMAND_GET_DRIVE_A_FAULT;    // Get the drive fault flag for motor A, indicates faults such as short-circuits and under voltage
	extern uint8_t COMMAND_GET_DRIVE_B_FAULT;    // Get the drive fault flag for motor B, indicates faults such as short-circuits and under voltage
	extern uint8_t COMMAND_SET_ALL_FWD;    // Set all motors PWM rate in a forwards direction
	extern uint8_t COMMAND_SET_ALL_REV;    // Set all motors PWM rate in a reverse direction
	extern uint8_t COMMAND_SET_FAILSAFE;    // Set the failsafe flag, turns the motors off if communication is interrupted
	extern uint8_t COMMAND_GET_FAILSAFE;    // Get the failsafe flag
	extern uint8_t COMMAND_GET_BATT_VOLT;    // Get the battery voltage reading
	extern uint8_t COMMAND_SET_BATT_LIMITS;    // Set the battery monitoring limits
	extern uint8_t COMMAND_GET_BATT_LIMITS;    // Get the battery monitoring limits
	extern uint8_t COMMAND_WRITE_EXTERNAL_LED;    // Write a 32bit pattern out to SK9822 / APA102C
	extern uint8_t COMMAND_GET_ID;  // Get the board identifier
	extern uint8_t COMMAND_SET_I2C_ADD;  // Set a new I2C address

	extern uint8_t COMMAND_VALUE_FWD;     // I2C value representing forward
	extern uint8_t COMMAND_VALUE_REV;     // I2C value representing reverse

	extern uint8_t COMMAND_VALUE_ON;     // I2C value representing on
	extern uint8_t COMMAND_VALUE_OFF;     // I2C value representing off

	extern int COMMAND_ANALOG_MAX; // Maximum value for analog readings

	// void Init(I2C *i2c);

	void SetLedShowBattery(I2C *i2c, bool state);

	void SetLed1(I2C *i2c, float r, float g, float b);

	void SetNewAddress(I2C *i2c, uint8_t newAddress);

	void SetMotor2(I2C *i2c, float power);

	float GetMotor2(I2C *i2c);

	void SetMotor1(I2C *i2c, float power);

	float GetMotor1(I2C *i2c);

	float GetBatteryReading(I2C *i2c);
}
	#endif
