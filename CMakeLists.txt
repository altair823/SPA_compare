cmake_minimum_required(VERSION 3.19)
project(SPA_compare)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SPA_compare
        dijkstra/dijkstra.cpp dijkstra/dijkstra.h main.cpp map/maze.cpp map/maze.h map/location.cpp map/location.h)
