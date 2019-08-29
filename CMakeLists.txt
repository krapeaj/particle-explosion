cmake_minimum_required(VERSION 3.14)
project(particle_explosion)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_library(Screen Screen.cpp)
add_library(Particle Particle.cpp)
add_library(Swarm Swarm.cpp)

add_executable(particle_explosion main.cpp)
target_link_libraries(particle_explosion PRIVATE ${SDL2_LIBRARIES})
target_link_libraries(particle_explosion PRIVATE Screen)
target_link_libraries(particle_explosion PRIVATE Particle)
target_link_libraries(particle_explosion PRIVATE Swarm)
