cmake_minimum_required(VERSION 3.6)

project(3DFileConverter)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra -Werror")

enable_testing()

add_subdirectory(lib)
add_subdirectory(converter)
add_subdirectory(test)
