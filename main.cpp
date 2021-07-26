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

    int mainLoopCount = 1;
    int mazeRowSize = DEFAULT_ROW;
    int mazeColumnSize = DEFAULT_COLUMN;
    if (argc == 4){
        mainLoopCount = int(std::strtol(argv[1], nullptr, 10));
        mazeRowSize = int(std::strtol(argv[2], nullptr, 10));
        mazeColumnSize = int(std::strtol(argv[3], nullptr, 10));
    } else if (argc == 2){
        mainLoopCount = int(std::strtol(argv[1], nullptr, 10));
    } else if (argc != 1){
        std::cout<<"Wrong arguments! The number of arguments must be 1(loop count) or 3(maze row size, maze column size, loop count)."<<std::endl;
    }


    CompareSP result;
    result.InitializeResultFile();

    float tick = (float)100/PROGRESSBAR_LEN;
    float percent = 0;
    int barCount = 0;

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

        std::cout<<loopCount+1<<"/"<<mainLoopCount<<" [";
        percent = (float)(loopCount+1)/(float)mainLoopCount*100;
        barCount = (int)(percent/tick);
        for(int i = 0; i < PROGRESSBAR_LEN; i++) {
			if (barCount > i) {
				std::cout<<"=";
			} else {
				std::cout<<" ";
			}
		}
        std::cout << std::fixed;
        std::cout.precision(2);
        std::cout << "] " << percent << "%%\r";
        std::cout.flush();
    }
    std::cout << "\nDone!" <<std::endl;
    return 0;
}