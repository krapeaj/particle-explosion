cmake_minimum_required(VERSION 3.14)
project(SDL_Basic)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(SDL_Basic main.cpp)
target_link_libraries(SDL_Basic ${SDL2_LIBRARIES})