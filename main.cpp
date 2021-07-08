//
// Created by 김태현 on 2021/07/07.
//

#include <iostream>
#include "map/maze.h"
#include "map/eller.h"

int main(){
    Maze maze;
    maze.PrintMaze();

    Eller eller;

    eller.MakeMaze(maze);

    std::cout<<std::endl;

    maze.PrintMaze();

}