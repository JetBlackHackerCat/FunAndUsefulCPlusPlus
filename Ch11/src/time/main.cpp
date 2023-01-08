#include <iostream>
#include <chrono>

using sys_clock = std::chrono::system_clock;

int main()
{
    sys_clock::time_point now = sys_clock::now();
    long unix_time = now.time_since_epoch().count();

    std::cout << "Current unix time is " << unix_time
              << std::endl;

    return 0;
}