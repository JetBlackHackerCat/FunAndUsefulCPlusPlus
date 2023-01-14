#include <iostream>
#include <chrono>
#include <thread>

const std::chrono::seconds period_seconds = std::chrono::seconds(1);

using hres_clock = std::chrono::high_resolution_clock;

int main()
{
    while (true)
    {
        hres_clock::time_point start_time = hres_clock::now();
        hres_clock::time_point target_time = start_time + period_seconds;

        long unix_time = start_time.time_since_epoch().count();

        std::cout << "Excecute task at: " << unix_time
                  << std::endl;

        std::this_thread::sleep_until(target_time);
    }

    return 0;
}