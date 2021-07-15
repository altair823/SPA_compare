//
// Created by 김태현 on 2021/07/07.
//

#ifndef SPA_COMPARE_LOCATION_H
#define SPA_COMPARE_LOCATION_H

#include <bitset>
#include "../declaration.h"

const int UP = 3;
const int DOWN = 2;
const int LEFT = 1;
const int RIGHT = 0;


class Location{
private:
    int xCoord;
    int yCoord;
    int weight[4];  // Edges to 4 adjacent cells.
    Location *adjacentLocations[4];

public:
    Location();
    Location(int row, int column);
    /*
     * Setters and getters.
     */
    void setXCoord(int);
    int getXCoord() const;
    void setYCoord(int);
    int getYCoord() const;
    void setWeight(int direction, int weightValue);
    int getWeight(int direction) const;
    void setAdjacent(int direction, Location *adjacent);
    Location *getAdjacent(int direction);

    bool operator==(const Location& otherLocation) const;
    bool operator!=(const Location& otherLocation) const;
    Location& operator=(const Location& location);
};

#endif //SPA_COMPARE_LOCATION_H
