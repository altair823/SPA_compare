//
// Created by 김태현 on 2021/07/23.
//

#include "AStar.h"

void AStar::setMaze(const Maze &mazeInput) {
    maze = mazeInput;
}

void AStar::setStart(int row, int column) {
    if (row < 0 || row >= MAX_ROW || column < 0 || column >= MAX_COLUMN) {
        std::cout << "Wrong Starting Point input in "<< getTypeName() << std::endl;
        exit(2);
    }
    start = maze[column][row];
}

void AStar::setDestination(int row, int column) {
    if (row < 0 || row >= MAX_ROW || column < 0 || column >= MAX_COLUMN){
        std::cout<<"Wrong Ending Point input in "<<getTypeName()<<std::endl;
        exit(2);
    }
    end = maze[column][row];

}

void AStar::FindSP() {

}
