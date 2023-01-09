#include <iostream>
#include <thread>

int main()
{
    std::cout << "Starting threads..." << std::endl;

    std::thread thread1 = std::thread([]() {
        std::cout << "Running thread 1" << std::endl;
    });

    std::thread thread2 = std::thread([]() {
        std::cout << "Running thread 2" << std::endl;
    });

    std::thread thread3 = std::thread([]() {
        std::cout << "Running thread 3" << std::endl;
    });

    thread1.join();
    thread2.join();
    thread3.join();

    return 0;
}