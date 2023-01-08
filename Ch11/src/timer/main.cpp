#include <iostream>
#include <chrono>
#include <unistd.h>

const int period_micros = 1000000;

using hres_clock = std::chrono::high_resolution_clock;

int main()
{
    while (true)
    {
        hres_clock::time_point start_time = hres_clock::now();
        long unix_time = start_time.time_since_epoch().count();

        std::cout << "Excecute task at: " << unix_time
                  << std::endl;

        hres_clock::time_point end_time = hres_clock::now();
        long elapsed_micros = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

        usleep(period_micros - elapsed_micros);
    }

    return 0;
}