#ifndef CONTROL_PWM
#define CONTROL_PWM

#include <stdlib.h>
#include <memory>
#include <string>
#include "i2c.h"

namespace fun::control {
  class PWM {
    private:
      std::unique_ptr<fun::common::I2C> _i2c;
    public:
      PWM(std::string path);
      bool init();
      void setDutyCycle(float percent);
      float getEncoder();
  };
}; // namespace fun::control

#endif /* !CONTROL_PWM */