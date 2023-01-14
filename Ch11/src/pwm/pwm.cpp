#include <iostream>
#include "pwm.h"

#define ENCODER_REG_ADD 0x08
#define DUTY_CYCLE_REG_ADD 0x09

fun::control::PWM::PWM(std::string i2c_path) 
{
  _i2c = std::make_unique<fun::common::I2C>(i2c_path);
}

bool fun::control::PWM::init()
{
  if (!_i2c->init())
  {
    std::cerr << "PWM failed to initialize." << std::endl;
    return false;
  }
  return true;
}

void fun::control::PWM::setDutyCycle(float percent)
{
  uint8_t value = 255 * percent;
  _i2c->write(DUTY_CYCLE_REG_ADD, value);
}

float fun::control::PWM::getEncoder()
{
  uint8_t buffer;
  _i2c->read(ENCODER_REG_ADD, buffer);
  return (float) buffer / 255;
}