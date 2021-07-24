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
#include "SPA/AStar.h"

int main(){

    for (int loopCount = 0; loopCount < MAIN_LOOP_COUNT; ++loopCount) {


        TimeMeasure timer;
        CompareSP result;

        // Make a new maze.
        timer.SetStart();
        Maze maze;
        Eller eller(maze);
        eller.MakeMaze();
        timer.SetEnd();
        timer.PrintTimeMs(eller.getTypeString());

#if _DIK

        // Run naive Dijkstra algorithm.
        DIK dik;
        dik.setMaze(maze);
        dik.setStart(0, MAX_COLUMN - 1);
        dik.setEnd(MAX_ROW - 1, 0);
        timer.SetStart();
        dik.FindSP();
        timer.SetEnd();
        result.InsertSP(&dik, timer.getTimeMs());

#endif

#if _DIKPQ

        // Run Dijkstra algorithm with priority queue.
        DIKPQ dikpq;
        dikpq.setMaze(maze);
        dikpq.setStart(0, MAX_COLUMN - 1);
        dikpq.setEnd(MAX_ROW - 1, 0);
        timer.SetStart();
        dikpq.FindSP();
        timer.SetEnd();
        //dikpq.printLocationDistSet();
        result.InsertSP(&dikpq, timer.getTimeMs());


#endif

#if _ASTAR

        AStar aStar;
        aStar.setMaze(maze);
        aStar.setStart(0, MAX_COLUMN - 1);
        aStar.setEnd(MAX_ROW - 1, 0);
        aStar.makeDistTable();
        timer.SetStart();
        aStar.FindSP();
        timer.SetEnd();
        //aStar.printLocationDistSet();
        result.InsertSP(&aStar, timer.getTimeMs());

#endif

        // Print all result.
        result.PrintAllSPAResult();
        //result.CompareAllSPList();

        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}