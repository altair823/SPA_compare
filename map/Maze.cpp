//
// Created by 김태현 on 2021/07/07.
//

#include "Maze.h"


Maze::Maze() {
    mazeNumber = 0;
    for (int column = 0; column < MAX_COLUMN; column++){
        for (int row = 0; row < MAX_ROW; ++row) {
            location[column][row].setXCoord(row);
            location[column][row].setYCoord(column);
        }
    }
}

void Maze::InitializeMaze(){
    for (int column = 0; column < MAX_COLUMN; column++){
        for (int row = 0; row < MAX_ROW; ++row) {
            location[column][row].setXCoord(row);
            location[column][row].setYCoord(column);
        }
    }
}

void Maze::IncreaseMazeNumber(){
    mazeNumber++;
}


void Maze::PrintMaze() const{
    for (const auto & column : location) {
        for (const auto row : column) {
            if (row.getOpenFlag(UP) != INF){
                std::cout<<"U";
            } else {std::cout<<"*";}
            if (row.getOpenFlag(DOWN) != INF){
                std::cout<<"D";
            }else {std::cout<<"*";}
            if (row.getOpenFlag(LEFT) != INF){
                std::cout<<"L";
            }else {std::cout<<"*";}
            if (row.getOpenFlag(RIGHT) != INF){
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
        (row == MAX_ROW - 1 && direction == RIGHT) ||
        (column == 0 && direction == UP) ||
        (column == MAX_COLUMN-1 && direction == DOWN)){
        return;
    }
    // Open the wall in current cell location.
    location[column][row].setOpenDirection(direction, weight);

    // Open the wall in corresponding cell location.
    switch (direction) {
        case UP:
            location[column-1][row].setOpenDirection(DOWN, weight);
            break;
        case DOWN:
            location[column+1][row].setOpenDirection(UP, weight);
            break;
        case LEFT:
            location[column][row - 1].setOpenDirection(RIGHT, weight);
            break;
        case RIGHT:
            location[column][row + 1].setOpenDirection(LEFT, weight);
            break;
        default:
            std::cout<<"There is no adjacent cell in "<< direction <<" direction!"<<std::endl;
            exit(1);
    }
}

void Maze::SaveMazeFile() {
    std::ofstream mazeFile;
    std::string filename = "maze" + std::to_string(mazeNumber);
    filename += ".txt";
    mazeFile.open(filename);
    for (int column = 0; column < MAX_COLUMN; ++column) {
        for (int row = 0; row < MAX_ROW; ++row) {
            if (location[column][row].getOpenFlag(UP) != INF){
                mazeFile<<"U";
            } else{
                mazeFile<<"*";
            }
            if (location[column][row].getOpenFlag(DOWN) != INF){
                mazeFile<<"D";
            } else{
                mazeFile<<"*";
            }
            if (location[column][row].getOpenFlag(LEFT) != INF){
                mazeFile<<"L";
            } else{
                mazeFile<<"*";
            }
            if (location[column][row].getOpenFlag(RIGHT) != INF){
                mazeFile<<"R";
            } else{
                mazeFile<<"*";
            }
            mazeFile<<" ";
        }
        mazeFile<<"\n";
    }
    mazeFile.close();
}



