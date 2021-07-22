cmake_minimum_required(VERSION 3.15)
project(SPA_compare)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SPA_compare
        SPA/DIK.cpp SPA/DIK.h main.cpp map/Maze.cpp map/Maze.h map/Location.cpp map/Location.h declaration.h map/Eller.cpp map/Eller.h SPA/SPAInterface.h structure/HeapTree.cpp structure/HeapTree.h structure/PriorityQueue.cpp structure/PriorityQueue.h SPA/DIKPQ.cpp SPA/DIKPQ.h analyze/TimeMeasure.cpp analyze/TimeMeasure.h analyze/CompareSP.cpp analyze/CompareSP.h)

