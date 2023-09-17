cmake_minimum_required(VERSION 3.8)
project(moving_average)

if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 17)
endif()

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

include_directories(include)

add_executable(main src/main.cpp)
