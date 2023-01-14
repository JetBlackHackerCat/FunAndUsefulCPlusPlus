#ifndef COMMON_I2C
#define COMMON_I2C

#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>

namespace fun::common {
  class I2C {
    private:
      std::string _path;
      int _i2c_bus;
    public:
      I2C(std::string path);
      ~I2C();
      bool init();
      void read(uint8_t reg_addr, uint8_t &ret_val);
      void write(uint8_t reg_addr, uint8_t val);
  };
}; // namespace fun::common

#endif /* !COMMON_I2C */