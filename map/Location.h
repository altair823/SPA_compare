//
// Created by 김태현 on 2021/07/07.
//

#ifndef SPA_COMPARE_LOCATION_H
#define SPA_COMPARE_LOCATION_H

#include <bitset>
#include "declaration.h"

const int UP = 3;
const int DOWN = 2;
const int LEFT = 1;
const int RIGHT = 0;


class Location{
private:
    int xCoord;
    int yCoord;
    std::bitset<4> openDirection;  // 0 is open, while 0 is close.

public:
    Location();
    /*
     * Setters and getters.
     */
    void setXCoord(int);
    int getXCoord() const;
    void setYCoord(int);
    int getYCoord() const;
    void setOpenFlag(std::bitset<4> openFlag);

    /*
     * The number of direction wanted to change is given by first.
     * After that, the certain direction values to set 'open' are given.
     */
    void setOpenDirection(int direction);
    std::bitset<4> getOpenFlag() const;
};

#endif //SPA_COMPARE_LOCATION_H
