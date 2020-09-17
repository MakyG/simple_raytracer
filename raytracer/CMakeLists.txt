project(raytracer)

add_library(raytracer STATIC Raytracer.cpp)

target_include_directories(raytracer PUBLIC .)
