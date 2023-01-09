#include <iostream>
#include "pwm.h"

int main()
{
    fun::control::PWM pwm("/dev/i2c-1");

    float speed = pwm.getEncoder();
    std::cout << "Current Speed " << speed << std::endl;

    pwm.setDutyCycle(0.5);
    std::cout << "Setting duty cycle to 50%" << std::endl;

    return 0;
}