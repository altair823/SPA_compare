//
// Created by 김태현 on 2021/07/07.
//

#include <iostream>
#include "map/Maze.h"
#include "map/Eller.h"
#include "SPA/Dik.h"

int main(){
    Maze maze;

    Eller eller(maze);

    eller.MakeMaze();

    maze.PrintMaze();

    /*
    DIK dik;
    dik.setMaze(maze);
    dik.setStart(0, 0);
    dik.setDestination(49, 49);
    dik.FindSP();
    dik.printLocationDistSet();
*/
}