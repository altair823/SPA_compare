//
// Created by 김태현 on 2021/07/07.
//

#include <iostream>
#include "analyze/TimeMeasure.h"
#include "map/Maze.h"
#include "map/Eller.h"
#include "SPA/DIK.h"
#include "SPA/DIKPQ.h"

int main(){
    TimeMeasure timer;

    timer.SetStart();
    Maze maze;

    Eller eller(maze);

    eller.MakeMaze();

    maze.PrintMaze();
    timer.SetEnd();
    timer.PrintTimeMs();
    std::cout<<std::endl;

    timer.SetStart();

    DIKPQ dikpq;
    dikpq.setMaze(maze);
    dikpq.setStart(0, MAX_COLUMN-1);
    dikpq.setDestination(MAX_ROW-1, 0);
    dikpq.FindSP();
    dikpq.printLocationDistSet();

    timer.SetEnd();
    timer.PrintTimeMs();

    std::cout<<std::endl;

    timer.SetStart();

    DIK dik;
    dik.setMaze(maze);
    dik.setStart(0, 49);
    dik.setDestination(49, 0);
    dik.FindSP();
    dik.printLocationDistSet();

    timer.SetEnd();
    timer.PrintTimeMs();
}