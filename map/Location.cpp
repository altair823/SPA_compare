//
// Created by 김태현 on 2021/07/07.
//
#include "Location.h"

Location::Location() {
    row = 0;
    column = 0;
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
    row = row;
    column = column;
    weight[0] = INF;
    weight[1] = INF;
    weight[2] = INF;
    weight[3] = INF;
    adjacentLocations[0] = nullptr;
    adjacentLocations[1] = nullptr;
    adjacentLocations[2] = nullptr;
    adjacentLocations[3] = nullptr;
}

void Location::setRow(int x) {
    row = x;
}

int Location::getRow() const {
    return row;
}

void Location::setColumn(int y) {
    column = y;
}

int Location::getColumn() const {
    return column;
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
    if (this->row == otherLocation.row and this->column == otherLocation.column){
        return true;
    } else{
        return false;
    }
}

bool Location::operator!=(const Location &otherLocation) const {
    if (this->row == otherLocation.row && this->column == otherLocation.column){
        return false;
    } else{
        return true;
    }
}

Location &Location::operator=(const Location &location) {
    row = location.row;
    column = location.column;
    for (int i = 0; i < MAX_EDGE_COUNT; i++) {
        weight[i] = location.weight[i];
        if (location.adjacentLocations[i] != nullptr) {
            this->adjacentLocations[i] = location.adjacentLocations[i];
        }
    }
    return *this;
}

std::ostream &operator<<(std::ostream &outputStream, const Location &location) {
    outputStream<<"r:"<<location.getRow()<<",c:"<<location.getColumn();
    return outputStream;
}


