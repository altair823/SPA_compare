//
// Created by κΉνν on 2021/07/07.
//

#include "Maze.h"


Maze::Maze(int rowSize, int columnSize, int stdInput) {
    maxRow = rowSize;
    maxColumn = columnSize;
    standardDeviation = stdInput;
    for (int column = 0; column < maxColumn; column++){
        for (int row = 0; row < maxRow; ++row) {
            location[column][row].setRow(row);
            location[column][row].setColumn(column);
            ConnectAdjacentLoc(row, column);
        }
    }
}

void Maze::InitializeMaze(){
    for (int column = 0; column < maxColumn; column++){
        for (int row = 0; row < maxRow; ++row) {
            location[column][row].setRow(row);
            location[column][row].setColumn(column);
        }
    }
}

void Maze::ConnectAdjacentLoc(int row, int column) {
    if (column == 0) {
        location[column][row].setAdjacent(UP, nullptr);
    } else{
        location[column][row].setAdjacent(UP, &location[column - 1][row]);
    }
    if (column == maxColumn - 1){
        location[column][row].setAdjacent(DOWN, nullptr);
    } else{
        location[column][row].setAdjacent(DOWN, &location[column + 1][row]);
    }
    if (row == 0){
        location[column][row].setAdjacent(LEFT, nullptr);
    } else{
        location[column][row].setAdjacent(LEFT, &location[column][row - 1]);
    }
    if (row == maxRow - 1){
        location[column][row].setAdjacent(RIGHT, nullptr);
    } else{
        location[column][row].setAdjacent(RIGHT, &location[column][row + 1]);
    }
}



void Maze::PrintMaze() const{
    for (const auto & column : location) {
        for (const auto row : column) {
            if (row.getWeight(UP) != INF){
                std::cout<<"U";
            } else {std::cout<<"*";}
            if (row.getWeight(DOWN) != INF){
                std::cout<<"D";
            }else {std::cout<<"*";}
            if (row.getWeight(LEFT) != INF){
                std::cout<<"L";
            }else {std::cout<<"*";}
            if (row.getWeight(RIGHT) != INF){
                std::cout<<"R";
            }else {std::cout<<"*";}
            std::cout << " ";
        }
        std::cout<<"\n";
    }
}

Location * Maze::operator[] (int index) {
    if (index < 0) {
        std::cout << "Array index out of bound exception" << std::endl;
        exit(1);
    }
    return location[index];
}

const Location * Maze::operator[] (int index) const{
    if (index < 0) {
        std::cout << "Array index out of bound exception" << std::endl;
        exit(1);
    }
    return location[index];
}

void Maze::OpenWall(int row, int column, int direction, int weight) {
    if ((row == 0 && direction == LEFT) ||
        (row == maxRow - 1 && direction == RIGHT) ||
        (column == 0 && direction == UP) ||
        (column == maxColumn-1 && direction == DOWN)){
        return;
    }
    // Open the wall in current cell location.
    location[column][row].setWeight(direction, weight);

    // Open the wall in corresponding cell location.
    switch (direction) {
        case UP:
            location[column - 1][row].setWeight(DOWN, weight);
            break;
        case DOWN:
            location[column + 1][row].setWeight(UP, weight);
            break;
        case LEFT:
            location[column][row - 1].setWeight(RIGHT, weight);
            break;
        case RIGHT:
            location[column][row + 1].setWeight(LEFT, weight);
            break;
        default:
            std::cout<<"There is no adjacent cell in "<< direction <<" direction!"<<std::endl;
            exit(1);
    }
}

int Maze::getRowSize() {
    return maxRow;
}

int Maze::getColumnSize() {
    return maxColumn;
}

Location *Maze::getLocation(int row, int column) {
    return &(location[column][row]);
}

int Maze::getStandardDeviation() const {
    return standardDeviation;
}



