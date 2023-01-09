#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>

#define I2C_DEV_ADD 0x69
#define I2C_REG_ADD 0x42
#define I2C_CTR_ADD 0xAB

int main()
{
    int i2c = open("/dev/i2c-0", O_RDWR);

    if (ioctl(i2c, I2C_SLAVE, I2C_DEV_ADD) < 0)
    {
        std::cerr << "Unable to communicate over I2C bus" << std::endl;
        return 1;
    }

    uint8_t control[2];
    control[0] = I2C_CTR_ADD;
    control[1] = 123;
    write(i2c, control, 2);

    uint8_t request[1];
    request[0] = I2C_REG_ADD;
    write(i2c, request, 2);
    uint8_t response[1];
    read(i2c, &response, 1);

    std::cout << "Received " << response[0] << std::endl;

    return 0;
}