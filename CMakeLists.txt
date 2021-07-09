cmake_minimum_required(VERSION 3.19)
project(SPA_compare)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SPA_compare
        SPA/Dik.cpp SPA/Dik.h main.cpp map/Maze.cpp map/Maze.h map/Location.cpp map/Location.h declaration.h map/Eller.cpp map/Eller.h SPA/spa_interface.h)
