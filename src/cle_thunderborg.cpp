#include "cle_thunderborg.h"

//ThunderBorg::ThunderBorg1 (byte redPin, byte greenPin, byte bluePin) {
//	this->redPin   = redPin;
//	this->greenPin = greenPin;
//	this->bluePin  = bluePin;
//}

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
  if (state == true) {
    Wire.write(1);              // sends one byte
	Wire.write(0);              // sends one byte
	//uint8_t buf[2] = {COMMAND_SET_LED_BATT_MON, COMMAND_VALUE_ON};
    //i2c->write_bytes(buf, 2);
  }
  else {
    //uint8_t buf[2] = {COMMAND_SET_LED_BATT_MON, COMMAND_VALUE_OFF};
    //i2c->write_bytes(buf, 2);
  }
}

void ThunderBorg::SetLed1(byte r, byte g, byte b){
	Wire.begin();
	Wire.beginTransmission(I2C_ID_THUNDERBORG); // transmit to device 
	Wire.write(1);              // sends one byte
	Wire.write(r);              // sends one byte
	Wire.write(g);              // sends one byte
	Wire.write(b);              // sends one byte
	Wire.endTransmission();    // stop transmitting
}

void ThunderBorg::SetMotor1(byte power){



  //uint8_t command, pwm;
  //if (power < 0.0) {
  //  command = COMMAND_SET_A_REV;
  //  pwm = -((int) (((float) PWM_MAX) * power));
  //  if (pwm > PWM_MAX) {
  //    pwm = PWM_MAX;
  //  }
  //}
  //else {
  //  command = COMMAND_SET_A_FWD;
  //  pwm = (int) (((float) PWM_MAX) * power);
  //  if (pwm > PWM_MAX) {
  //    pwm = PWM_MAX;
  //  }
  //}
  //uint8_t buf[] = {command, pwm};
  //i2c->write_bytes(buf, sizeof(buf) / sizeof(uint8_t));





	Wire.begin();
	Wire.beginTransmission(I2C_ID_THUNDERBORG);	// transmit to device 
	Wire.write(COMMAND_SET_A_FWD);				// sends one byte
	Wire.write(power);							// sends one byte
	Wire.endTransmission();						// stop transmitting	
}


void ThunderBorg::I2C_send_Buffer(){
	int i;
	Wire.begin();
	Wire.beginTransmission(I2C_ID_THUNDERBORG); //address is queued for checking if the slave is present
	//for (i = 0; i < sizeof(I2C_Buffer) - 1; i++){
	//{
	//	Wire.write(I2C_Buffer[i]);  //data bytes are queued in local buffer
	//}
	Wire.endTransmission(); //all the above queued bytes are sent to slave on ACK handshaking
}