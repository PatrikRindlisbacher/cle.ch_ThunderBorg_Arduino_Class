#ifndef __RGB_LED__
#define __RGB_LED__

#include <Arduino.h>
#include <Wire.h>

class RGBLed {
private:
	byte redPin;
	byte greenPin;
	byte bluePin;

public:
	RGBLed (byte redPin, byte greenPin, byte bluePin);
	//void Init(I2C *i2c);
	//void SetLedShowBattery(I2C *i2c, bool state);
	void SetLed1(byte XXX, byte r, byte g, byte b);
	//void SetNewAddress(I2C *i2c, uint8_t newAddress);
	//void SetMotor2(I2C *i2c, float power);
	//float GetMotor2(I2C *i2c);
	//void SetMotor1(I2C *i2c, float power);
	//float GetMotor1(I2C *i2c);
	//float GetBatteryReading(I2C *i2c);


	void setRGB(byte r, byte g, byte b) ;
	void blink(char color, byte times, unsigned int ms);
};

#endif