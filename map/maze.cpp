//
// Created by 김태현 on 2021/07/07.
//

#include "maze.h"


Maze::Maze() {
    for (int column = 0; column < MAX_COLUMN; column++){
        for (int raw = 0; raw < MAX_RAW; ++raw) {
            location[column][raw].setXCoord(raw);
            location[column][raw].setYCoord(column);
            // Set all flags indicating directions open.
            /*
            location[column][raw].setOpenDirection(UP);
            location[column][raw].setOpenDirection(DOWN);
            location[column][raw].setOpenDirection(LEFT);
            location[column][raw].setOpenDirection(RIGHT);
             */
        }
    }
}


Location Maze::getLocation(int raw, int column) const{
    return location[column][raw];
}

void Maze::PrintMaze() const{
    for (const auto & column : location) {
        for (const auto raw : column) {
            if (raw.getOpenFlag().test(UP)){
                std::cout<<"U";
            } else {std::cout<<"*";}
            if (raw.getOpenFlag().test(DOWN)){
                std::cout<<"D";
            }else {std::cout<<"*";}
            if (raw.getOpenFlag().test(LEFT)){
                std::cout<<"L";
            }else {std::cout<<"*";}
            if (raw.getOpenFlag().test(RIGHT)){
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

void Maze::OpenWall(int raw, int column, int direction) {
    if ((raw == 0 && direction == LEFT) ||
            (raw == MAX_RAW-1 && direction == RIGHT) ||
            (column == 0 && direction == UP) ||
            (column == MAX_COLUMN-1 && direction == DOWN)){
        return;
    }
    // Open the wall in current cell location.
    location[column][raw].setOpenDirection(direction);

    // Open the wall in corresponding cell location.
    switch (direction) {
        case UP:
            location[column-1][raw].setOpenDirection(DOWN);
            break;
        case DOWN:
            location[column+1][raw].setOpenDirection(UP);
            break;
        case LEFT:
            location[column][raw-1].setOpenDirection(RIGHT);
            break;
        case RIGHT:
            location[column][raw+1].setOpenDirection(LEFT);
            break;
        default:
            std::cout<<"There is no adjacent cell in "<< direction <<" direction!"<<std::endl;
            exit(1);
    }
}




