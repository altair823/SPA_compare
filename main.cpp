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

int main(int argc, char * argv []){

    int mainLoopCount = 0;
    int mazeRowSize = 0;
    int mazeColumnSize = 0;
    if (std::strtol(argv[1], nullptr, 10) == 0){
        mainLoopCount = 1;
        mazeRowSize = DEFAULT_ROW;
        mazeColumnSize= DEFAULT_COLUMN;
    } else if (argc == 4){
        mainLoopCount = int(std::strtol(argv[1], nullptr, 10));
        mazeRowSize = int(std::strtol(argv[2], nullptr, 10));
        mazeColumnSize = int(std::strtol(argv[3], nullptr, 10));
    } else if (argc == 2){
        mainLoopCount = int(std::strtol(argv[1], nullptr, 10));
        mazeRowSize = DEFAULT_ROW;
        mazeColumnSize = DEFAULT_COLUMN;
    } else{
        std::cout<<"Wrong arguments! The number of arguments must be 1(loop count) or 3(maze row size, maze column size, loop count)."<<std::endl;
    }


    CompareSP result;
    result.InitializeResultFile();

    for (int loopCount = 0; loopCount < mainLoopCount; ++loopCount) {
        result.InitializeResultData();
        result.setRoundNum(loopCount + 1);
        TimeMeasure timer;

        // Make a new maze.
        timer.SetStart();
        Maze maze(mazeRowSize, mazeColumnSize);
        Eller eller(maze);
        eller.MakeMaze();
        timer.SetEnd();

#if _DIK

        // Run naive Dijkstra algorithm.
        DIK dik;
        dik.setMaze(maze);
        dik.setStart(0, mazeColumnSize - 1);
        dik.setEnd(mazeRowSize - 1, 0);
        timer.SetStart();
        dik.FindSP();
        timer.SetEnd();
        result.InsertSP(&dik, timer.getTimeMs());

#endif

#if _DIKPQ

        // Run Dijkstra algorithm with priority queue.
        DIKPQ dikpq;
        dikpq.setMaze(maze);
        dikpq.setStart(0, mazeColumnSize - 1);
        dikpq.setEnd(mazeRowSize - 1, 0);
        timer.SetStart();
        dikpq.FindSP();
        timer.SetEnd();
        result.InsertSP(&dikpq, timer.getTimeMs());


#endif

#if _ASTAR

        AStar aStar;
        aStar.setMaze(maze);
        aStar.setStart(0, mazeColumnSize - 1);
        aStar.setEnd(mazeRowSize - 1, 0);
        aStar.makeDistTable();
        timer.SetStart();
        aStar.FindSP();
        timer.SetEnd();
        result.InsertSP(&aStar, timer.getTimeMs());

#endif

        result.SaveDataFiles();
    }
    return 0;
}