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
            location[column][raw].setOpenDirection(4, UP, DOWN, LEFT, RIGHT);
        }
    }
}


Location Maze::getLocation(int x, int y) const{
    return location[y][x];
}

void Maze::PrintMaze() const{
    for (const auto & column : location) {
        for (const auto raw : column) {
            std::cout << raw.getOpenFlag() << " ";
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




