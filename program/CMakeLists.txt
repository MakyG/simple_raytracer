project(program)

add_executable(program main.cpp ./ui/Menu.cpp)
target_link_libraries(program raytracer)