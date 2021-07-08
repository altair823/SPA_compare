//
// Created by 김태현 on 2021/07/07.
//
#include "location.h"

Location::Location() {
    openDirection.reset();
    xCoord = 0;
    yCoord = 0;
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

void Location::setOpenDirection(int openDirCount, ...) {
    va_list ap;
    va_start(ap, openDirCount);
    for (int i = 0; i < openDirCount; i++){
        openDirection.set(va_arg(ap, int));
    }
}

std::bitset<4> Location::getOpenFlag() const {
    return openDirection;
}

void Location::setOpenFlag(std::bitset<4> openFlag) {
    openDirection = openFlag;
}


