#include <iostream>
#include <chrono>
#include <thread>
#include "task.h"

int main()
{
    std::cout << "Starting tasks..." << std::endl;

    fun::common::Task task1(
        std::chrono::seconds(1),
        []() {
            std::cout << "Running task 1" << std::endl;
        }
    );

    fun::common::Task task2(
        std::chrono::seconds(2),
        []() {
            std::cout << "Running task 2" << std::endl;
        }
    );


    task1.start();
    task2.start();

    std::this_thread::sleep_for(std::chrono::seconds(30));

    task1.stop();
    task2.stop();

    std::cout << "Stopping tasks..." << std::endl;

    return 0;
}