cmake_minimum_required(VERSION 3.14)
project(SDL_Basic)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_library(Screen Screen.cpp)
add_library(Particle Particle.cpp)
add_library(Swarm Swarm.cpp)
#include_directories(${PROJECT_SOURCE_DIR})

add_executable(SDL_Basic main.cpp)
target_link_libraries(SDL_Basic PRIVATE ${SDL2_LIBRARIES})
target_link_libraries(SDL_Basic PRIVATE Screen)
target_link_libraries(SDL_Basic PRIVATE Particle)
target_link_libraries(SDL_Basic PRIVATE Swarm)
