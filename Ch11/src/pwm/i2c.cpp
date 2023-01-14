#include <iostream>
#include "i2c.h"

fun::common::I2C::I2C(std::string path) : _path(path)
{
}

fun::common::I2C::~I2C()
{
  if (_i2c_bus > 0) {
    ::close(_i2c_bus);
  }
}

bool fun::common::I2C::init()
{
  _i2c_bus = ::open(_path.c_str(), O_RDWR);
  if (_i2c_bus < 0) {
    std::cerr << "Unable to open the I2C bus" << std::endl;
    return false;
  }
  return true;
}

void fun::common::I2C::read(uint8_t reg_addr, uint8_t &ret_val)
{
  ::write(_i2c_bus, &reg_addr, 1);
  ::read(_i2c_bus, &ret_val, 1);
}

void fun::common::I2C::write(uint8_t reg_addr, uint8_t val)
{
  uint8_t buf[2];
  buf[0] = reg_addr;
  buf[1] = val;
  ::write(_i2c_bus, buf, 2);
}