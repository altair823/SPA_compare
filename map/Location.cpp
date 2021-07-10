//
// Created by 김태현 on 2021/07/07.
//
#include "Location.h"

Location::Location() {
    xCoord = 0;
    yCoord = 0;
    openDirection[0] = INF;
    openDirection[1] = INF;
    openDirection[2] = INF;
    openDirection[3] = INF;
}

Location::Location(int row, int column) {
    xCoord = row;
    yCoord = column;
    openDirection[0] = INF;
    openDirection[1] = INF;
    openDirection[2] = INF;
    openDirection[3] = INF;
}

void Location::setXCoord(int x) {
    xCoord = x;
}

int Location::getXCoord() const {
    return xCoord;
}

void Location::setYCoord(int y) {
    yCoord = y;
}

int Location::getYCoord() const {
    return yCoord;
}

void Location::setOpenDirection(int direction, int weight) {
    openDirection[direction] = weight;
}

int Location::getOpenFlag(int direction) const {
    return openDirection[direction];
}


bool Location::operator==(Location &otherLocation) const {
    if (xCoord == otherLocation.xCoord && yCoord == otherLocation.yCoord){
        return true;
    } else{
        return false;
    }
}


