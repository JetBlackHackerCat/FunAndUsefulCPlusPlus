#include <iostream>
#include <thread>

int main() {
    std::cout << "Starting thread...\n";

    std::thread thread = std::thread([]() {
        std::cout << "Press Enter to exit thread...\n";
        std::cin.get();

        std::cout << "Exiting thread...\n";
    });

    std::cout << "Waiting for thread...\n";
    thread.join();

    return 0;
}