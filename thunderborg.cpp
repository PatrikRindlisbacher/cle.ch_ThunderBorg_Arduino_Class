#include "thunderborg.h"

// Constant values
int I2C_SLAVE                   = 0x0703;
uint8_t PWM_MAX                     = 255;
uint8_t I2C_MAX_LEN                 = 6;
float VOLTAGE_PIN_MAX             = 36.3;  // Maximum voltage from the analog voltage monitoring pin
float VOLTAGE_PIN_CORRECTION      = 0.0;   // Correction value for the analog voltage monitoring pin
float BATTERY_MIN_DEFAULT         = 7.0;   // Default minimum battery monitoring voltage
float BATTERY_MAX_DEFAULT         = 35.0;  // Default maximum battery monitoring voltage

uint8_t I2C_ID_THUNDERBORG          = 0x15;

uint8_t COMMAND_SET_LED1            = 1;     // Set the colour of the ThunderBorg LED
uint8_t COMMAND_GET_LED1            = 2;     // Get the colour of the ThunderBorg LED
uint8_t COMMAND_SET_LED2            = 3;     // Set the colour of the ThunderBorg Lid LED
uint8_t COMMAND_GET_LED2            = 4;     // Get the colour of the ThunderBorg Lid LED
uint8_t COMMAND_SET_LEDS            = 5;     // Set the colour of both the LEDs
uint8_t COMMAND_SET_LED_BATT_MON    = 6;     // Set the colour of both LEDs to show the current battery level
uint8_t COMMAND_GET_LED_BATT_MON    = 7;     // Get the state of showing the current battery level via the LEDs
uint8_t COMMAND_SET_A_FWD           = 8;     // Set motor A PWM rate in a forwards direction
uint8_t COMMAND_SET_A_REV           = 9;     // Set motor A PWM rate in a reverse direction
uint8_t COMMAND_GET_A               = 10;    // Get motor A direction and PWM rate
uint8_t COMMAND_SET_B_FWD           = 11;    // Set motor B PWM rate in a forwards direction
uint8_t COMMAND_SET_B_REV           = 12;    // Set motor B PWM rate in a reverse direction
uint8_t COMMAND_GET_B               = 13;    // Get motor B direction and PWM rate
uint8_t COMMAND_ALL_OFF             = 14;    // Switch everything off
uint8_t COMMAND_GET_DRIVE_A_FAULT   = 15;    // Get the drive fault flag for motor A, indicates faults such as short-circuits and under voltage
uint8_t COMMAND_GET_DRIVE_B_FAULT   = 16;    // Get the drive fault flag for motor B, indicates faults such as short-circuits and under voltage
uint8_t COMMAND_SET_ALL_FWD         = 17;    // Set all motors PWM rate in a forwards direction
uint8_t COMMAND_SET_ALL_REV         = 18;    // Set all motors PWM rate in a reverse direction
uint8_t COMMAND_SET_FAILSAFE        = 19;    // Set the failsafe flag, turns the motors off if communication is interrupted
uint8_t COMMAND_GET_FAILSAFE        = 20;    // Get the failsafe flag
uint8_t COMMAND_GET_BATT_VOLT       = 21;    // Get the battery voltage reading
uint8_t COMMAND_SET_BATT_LIMITS     = 22;    // Set the battery monitoring limits
uint8_t COMMAND_GET_BATT_LIMITS     = 23;    // Get the battery monitoring limits
uint8_t COMMAND_WRITE_EXTERNAL_LED  = 24;    // Write a 32bit pattern out to SK9822 / APA102C
uint8_t COMMAND_GET_ID              = 0x99;  // Get the board identifier
uint8_t COMMAND_SET_I2C_ADD         = 0xAA;  // Set a new I2C address

uint8_t COMMAND_VALUE_FWD           = 1;     // I2C value representing forward
uint8_t COMMAND_VALUE_REV           = 2;     // I2C value representing reverse

uint8_t COMMAND_VALUE_ON            = 1;     // I2C value representing on
uint8_t COMMAND_VALUE_OFF           = 0;     // I2C value representing off

int COMMAND_ANALOG_MAX          = 0x3FF; // Maximum value for analog readings

//void Init(I2C *i2c) {
//  i2c->write_bytes(&COMMAND_GET_ID, 1);
//  uint8_t readbuf[I2C_MAX_LEN];
//  i2c->read_bytes(readbuf, I2C_MAX_LEN);
//  printf("Found I2C device with ID: %#08x\n", readbuf[1]);
//}

void SetLedShowBattery(I2C *i2c, bool state) {
  if (state == true) {
    uint8_t buf[2] = {COMMAND_SET_LED_BATT_MON, COMMAND_VALUE_ON};
    i2c->write_bytes(buf, 2);
  }
  else {
    uint8_t buf[2] = {COMMAND_SET_LED_BATT_MON, COMMAND_VALUE_OFF};
    i2c->write_bytes(buf, 2);
  }
}

void SetLed1(I2C *i2c, float r, float g, float b) {
  r *= PWM_MAX;
  g *= PWM_MAX;
  b *= PWM_MAX;
  uint8_t r_int = (uint8_t) r;
  uint8_t g_int = (uint8_t) g;
  uint8_t b_int = (uint8_t) b;
  uint8_t buf[] = {COMMAND_SET_LED1, r_int, g_int, b_int};
  i2c->write_bytes(buf, sizeof(buf) / sizeof(uint8_t));
}

void SetNewAddress(I2C *i2c, uint8_t newAddress) {
  if (newAddress < 0x03 || newAddress > 0x77) {
    printf("Error, I2C addresses below 0x03 and above 0x77 are reserved.");
  }
  uint8_t buf[2] = {COMMAND_SET_I2C_ADD, newAddress};
  i2c->write_bytes(buf, sizeof(buf) / sizeof(uint8_t));
  i2c->change_address(newAddress);
  Init(i2c);
}

void SetMotor2(I2C *i2c, float power) {
  uint8_t command, pwm;
  if (power < 0.0) {
    command = COMMAND_SET_B_REV;
    pwm = -((int) (((float) PWM_MAX) * power));
    if (pwm > PWM_MAX) {
      pwm = PWM_MAX;
    }
  }
  else {
    command = COMMAND_SET_B_FWD;
    pwm = (int) (((float) PWM_MAX) * power);
    if (pwm > PWM_MAX) {
      pwm = PWM_MAX;
    }
  }
  uint8_t buf[] = {command, pwm};
  i2c->write_bytes(buf, sizeof(buf) / sizeof(uint8_t));
  /*
  if (round(GetMotor2(i2c) * PWM_MAX) != pwm) {
    printf("Error: SetMotor2 could not set the motor power.\n");
  }
  */
}

float GetMotor2(I2C *i2c) {
  i2c->write_bytes(&COMMAND_GET_B, 1);
  uint8_t buf[I2C_MAX_LEN];
  i2c->read_bytes(buf, I2C_MAX_LEN);
  float power = ((float) buf[2]) / ((float) PWM_MAX);
  if (buf[1] == COMMAND_VALUE_FWD) {
    return power;
  }
  else if (buf[1] == COMMAND_VALUE_REV) {
    return -power;
  }
  else {
    printf("Error: GetMotor2 could not get the motor power.\n");
    return 0.0;
  }
}

void SetMotor1(I2C *i2c, float power) {
  uint8_t command, pwm;
  if (power < 0.0) {
    command = COMMAND_SET_A_REV;
    pwm = -((int) (((float) PWM_MAX) * power));
    if (pwm > PWM_MAX) {
      pwm = PWM_MAX;
    }
  }
  else {
    command = COMMAND_SET_A_FWD;
    pwm = (int) (((float) PWM_MAX) * power);
    if (pwm > PWM_MAX) {
      pwm = PWM_MAX;
    }
  }
  uint8_t buf[] = {command, pwm};
  i2c->write_bytes(buf, sizeof(buf) / sizeof(uint8_t));
  /*
  if (round(GetMotor1(i2c) * PWM_MAX) != pwm) {
    printf("Error: SetMotor1 could not set the motor power.\n");
  }
  */
}

float GetMotor1(I2C *i2c) {
  i2c->write_bytes(&COMMAND_GET_A, 1);
  uint8_t buf[I2C_MAX_LEN];
  i2c->read_bytes(buf, I2C_MAX_LEN);
  float power = ((float) buf[2]) / ((float) PWM_MAX);
  if (buf[1] == COMMAND_VALUE_FWD) {
    return power;
  }
  else if (buf[1] == COMMAND_VALUE_REV) {
    return -power;
  }
  else {
    printf("Error: GetMotor1 could not get the motor power.\n");
    return 0.0;
  }
}

float GetBatteryReading(I2C *i2c) {
  i2c->write_bytes(&COMMAND_GET_BATT_VOLT, 1);
  uint8_t buf[I2C_MAX_LEN];
  i2c->read_bytes(buf, I2C_MAX_LEN);
  int raw = (buf[1] << 8) + buf[2];
  float level = ((float) raw) / ((float) COMMAND_ANALOG_MAX);
  level *= VOLTAGE_PIN_MAX;
  return level + VOLTAGE_PIN_CORRECTION;
}
