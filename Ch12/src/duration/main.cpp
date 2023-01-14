#include <iostream>
#include <chrono>
#include <cstdlib>

const int amount = 1000;

using hres_clock = std::chrono::high_resolution_clock;

int main()
{
    hres_clock::time_point start_time = hres_clock::now();

    for (int i = 0; i < amount; i++)
    {
        int number = rand();
    }

    hres_clock::time_point end_time = hres_clock::now();

    long elapsed_micros = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

    std::cout << "Generated " << amount << " random number in " << elapsed_micros << " microseconds\n"
              << std::endl;

    return 0;
}