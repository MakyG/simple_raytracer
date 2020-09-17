cmake_minimum_required(VERSION 3.17)

project(simple_raytracer)
# https://cmake.org/cmake/help/latest/prop_tgt/CXX_STANDARD.html
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# expected behaviour
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++lastest")
add_subdirectory(raytracer)
add_subdirectory(program)