cmake_minimum_required(VERSION 3.26)
project(Trip_Packing_Calculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --static")

add_executable(Trip_Packing_Calculator
        Trip_Packing_Calculator.cpp)
