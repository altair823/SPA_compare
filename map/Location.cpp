//
// Created by 김태현 on 2021/07/07.
//
#include "Location.h"

Location::Location() {
    xCoord = 0;
    yCoord = 0;
    weight[0] = INF;
    weight[1] = INF;
    weight[2] = INF;
    weight[3] = INF;
    adjacentLocations[0] = nullptr;
    adjacentLocations[1] = nullptr;
    adjacentLocations[2] = nullptr;
    adjacentLocations[3] = nullptr;
}

Location::Location(int row, int column) {
    xCoord = row;
    yCoord = column;
    weight[0] = INF;
    weight[1] = INF;
    weight[2] = INF;
    weight[3] = INF;
    adjacentLocations[0] = nullptr;
    adjacentLocations[1] = nullptr;
    adjacentLocations[2] = nullptr;
    adjacentLocations[3] = nullptr;
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

void Location::setWeight(int direction, int weightValue) {
    weight[direction] = weightValue;
}

int Location::getWeight(int direction) const {
    return weight[direction];
}

void Location::setAdjacent(int direction, Location *adjacent) {
    adjacentLocations[direction] = adjacent;
}

Location *Location::getAdjacent(int direction) {
    return adjacentLocations[direction];
}

bool Location::operator==(const Location &otherLocation) const {
    if (this->xCoord == otherLocation.xCoord and this->yCoord == otherLocation.yCoord){
        return true;
    } else{
        return false;
    }
}

bool Location::operator!=(const Location &otherLocation) const {
    if (this->xCoord == otherLocation.xCoord && this->yCoord == otherLocation.yCoord){
        return false;
    } else{
        return true;
    }
}

Location &Location::operator=(const Location &location) {
    xCoord = location.xCoord;
    yCoord = location.yCoord;
    for (int i = 0; i < MAX_EDGE_COUNT; i++) {
        weight[i] = location.weight[i];
        if (location.adjacentLocations[i] != nullptr) {
            this->adjacentLocations[i] = location.adjacentLocations[i];
        }
    }
    return *this;
}


