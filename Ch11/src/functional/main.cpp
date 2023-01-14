#include <iostream>
#include <chrono>
#include <thread>
#include <functional>

const std::chrono::seconds period_seconds = std::chrono::seconds(1);

using hres_clock = std::chrono::high_resolution_clock;

void task(long unix_time)
{
    std::cout << "Excecute standlone task at: " << unix_time
              << std::endl;
}

void start_timer(std::function<void(long)> fn)
{
    while (true)
    {
        hres_clock::time_point start_time = hres_clock::now();
        hres_clock::time_point target_time = start_time + period_seconds;
        long unix_time = start_time.time_since_epoch().count();
        fn(unix_time);
        std::this_thread::sleep_until(target_time);
    }
}

int main()
{
    start_timer(task);
    return 0;
}