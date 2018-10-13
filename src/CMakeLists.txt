cmake_minimum_required(VERSION 3.6)

project(3DFileConverter)

find_package(Git REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra -Werror")

add_executable(3DFileConverter main.cpp)

enable_testing()

add_subdirectory(test)