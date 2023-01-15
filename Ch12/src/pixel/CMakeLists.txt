# cmake needs this line

cmake_minimum_required(VERSION 3.1)

# Enable C++11

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Define project

project(fun LANGUAGES CXX)

# Find OpenCV

# set(OpenCV_DIR /usr/local/opencv4/lib/cmake/opencv4)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

# Display OpenCV info

message(STATUS "OpenCV library status:")

message(STATUS "    config: ${OpenCV_DIR}")

message(STATUS "    version: ${OpenCV_VERSION}")

message(STATUS "    libraries: ${OpenCV_LIBS}")

message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

# Declare the executable target

add_executable(fun main.cpp)

# Link application to OpenCV libraries

target_link_libraries(fun PRIVATE ${OpenCV_LIBS} ${CMAKE_DL_LIBS})
