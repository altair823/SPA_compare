//
// Created by 김태현 on 2021/07/07.
//

#include "maze.h"


Maze::Maze() {
    for (int column = 0; column < MAX_COLUMN; column++){
        for (int row = 0; row < MAX_ROW; ++row) {
            location[column][row].setXCoord(row);
            location[column][row].setYCoord(column);
            // Set all flags indicating directions open.
            /*
            location[column][row].setOpenDirection(UP);
            location[column][row].setOpenDirection(DOWN);
            location[column][row].setOpenDirection(LEFT);
            location[column][row].setOpenDirection(RIGHT);
             */
        }
    }
}


Location Maze::getLocation(int row, int column) const{
    return location[column][row];
}

void Maze::PrintMaze() const{
    for (const auto & column : location) {
        for (const auto row : column) {
            if (row.getOpenFlag().test(UP)){
                std::cout<<"U";
            } else {std::cout<<"*";}
            if (row.getOpenFlag().test(DOWN)){
                std::cout<<"D";
            }else {std::cout<<"*";}
            if (row.getOpenFlag().test(LEFT)){
                std::cout<<"L";
            }else {std::cout<<"*";}
            if (row.getOpenFlag().test(RIGHT)){
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

void Maze::OpenWall(int row, int column, int direction) {
    if ((row == 0 && direction == LEFT) ||
        (row == MAX_ROW - 1 && direction == RIGHT) ||
        (column == 0 && direction == UP) ||
        (column == MAX_COLUMN-1 && direction == DOWN)){
        return;
    }
    // Open the wall in current cell location.
    location[column][row].setOpenDirection(direction);

    // Open the wall in corresponding cell location.
    switch (direction) {
        case UP:
            location[column-1][row].setOpenDirection(DOWN);
            break;
        case DOWN:
            location[column+1][row].setOpenDirection(UP);
            break;
        case LEFT:
            location[column][row - 1].setOpenDirection(RIGHT);
            break;
        case RIGHT:
            location[column][row + 1].setOpenDirection(LEFT);
            break;
        default:
            std::cout<<"There is no adjacent cell in "<< direction <<" direction!"<<std::endl;
            exit(1);
    }
}




