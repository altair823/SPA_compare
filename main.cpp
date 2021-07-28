//
// Created by 김태현 on 2021/07/07.
//

#include <iostream>
#include <memory>
#include "analyze/TimeMeasure.h"
#include "analyze/CompareSP.h"
#include "map/Maze.h"
#include "map/Eller.h"
#include "SPA/DIK.h"
#include "SPA/DIKPQ.h"
#include "SPA/DIKBQ.h"
#include "SPA/ASPQ.h"
#include "SPA/ASBQ.h"

int main(int argc, char * argv []){

    int mainLoopCount = 1;
    int mazeRowSize = DEFAULT_ROW;
    int mazeColumnSize = DEFAULT_COLUMN;
    int standardDeviation = 0;
    if (argc == 5){
        mainLoopCount = int(std::strtol(argv[1], nullptr, 10));
        mazeRowSize = int(std::strtol(argv[2], nullptr, 10));
        mazeColumnSize = int(std::strtol(argv[3], nullptr, 10));
        standardDeviation = int(std::strtol(argv[4], nullptr, 10));
    } else if (argc == 2){
        mainLoopCount = int(std::strtol(argv[1], nullptr, 10));
    } else if (argc != 1){
        std::cout<<"Wrong arguments! The number of arguments must be 1(loop count) or 4(maze row size, maze column size, loop count, standard deviation)."<<std::endl;
        return 1;
    }


    CompareSP result;
    result.InitializeResultFile();

    float tick = (float)100/PROGRESSBAR_LEN;
    float percent;
    int barCount;

    for (int loopCount = 0; loopCount < mainLoopCount; ++loopCount) {

        result.InitializeResultData();
        result.setRoundNum(loopCount + 1);
        TimeMeasure timer;

        // Make a new maze.
        timer.SetStart();
        Maze maze(mazeRowSize, mazeColumnSize, standardDeviation);
        Eller eller(maze);
        eller.MakeMaze();
        timer.SetEnd();


        DIK dik;
        DIKPQ dikpq;
        DIKBQ dikbq;
        ASPQ aspq;
        ASBQ asbq;

        std::vector<std::unique_ptr<SPAInterface>> SPAList;

#if _DIK
        SPAList.push_back(std::make_unique<DIK>());
#endif
#if _DIKPQ
        SPAList.push_back(std::make_unique<DIKPQ>());
#endif
#if _DIKBQ
        SPAList.push_back(std::make_unique<DIKBQ>());
#endif
#if _ASPQ
        SPAList.push_back(std::make_unique<ASPQ>());
#endif
#if _ASBQ
        SPAList.push_back(std::make_unique<ASBQ>());
#endif

        for (auto & spa : SPAList) {
            spa->setMaze(maze);
            spa->setStart(0, mazeColumnSize - 1);
            spa->setEnd(mazeRowSize - 1, 0);
            if (spa->getTypeName() == "ASPQ  " || spa->getTypeName() == "ASBQ  "){
                spa->makeDistTable();
            }
            timer.SetStart();
            spa->FindSP();
            timer.SetEnd();
            result.InsertSP(spa.release(), timer.getTimeMs());
        }

        result.SaveDataFiles();
        SPAList.clear();

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