//
// Created by 김태현 on 2021/07/07.
//

#include <iostream>
#include "analyze/TimeMeasure.h"
#include "analyze/CompareSP.h"
#include "map/Maze.h"
#include "map/Eller.h"
#include "SPA/DIK.h"
#include "SPA/DIKPQ.h"

int main(){
    TimeMeasure timer;
    CompareSP result;

    // Make a new maze.
    timer.SetStart();
    Maze maze;
    Eller eller(maze);
    eller.MakeMaze();
    maze.PrintMaze();
    timer.SetEnd();
    timer.PrintTimeMs();
    std::cout<<std::endl;

#if _DIK

    // Run naive Dijkstra algorithm.
    timer.SetStart();
    DIK dik;
    dik.setMaze(maze);
    dik.setStart(0, 49);
    dik.setDestination(49, 0);
    dik.FindSP();
    dik.printLocationDistSet();
    result.insertSP(dik);
    timer.SetEnd();
    timer.PrintTimeMs();

    std::cout<<std::endl;

#endif

#if _DIKPQ

    // Run Dijkstra algorithm with priority queue.
    timer.SetStart();
    DIKPQ dikpq;
    dikpq.setMaze(maze);
    dikpq.setStart(0, MAX_COLUMN-1);
    dikpq.setDestination(MAX_ROW-1, 0);
    dikpq.FindSP();
    dikpq.printLocationDistSet();
    result.insertSP(dikpq);
    timer.SetEnd();
    timer.PrintTimeMs();

#endif

    // Print all result.
    result.printAllSPAResult();
}