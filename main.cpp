//
// Created by 김태현 on 2021/07/07.
//

#include <iostream>
#include "map/Maze.h"
#include "map/Eller.h"

int main(){
    Maze maze;

    Eller eller(maze);

    eller.MakeMaze();

    maze.PrintMaze();

}