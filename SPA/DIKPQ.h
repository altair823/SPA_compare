//
// Created by 김태현 on 2021/07/15.
//

#ifndef SPA_COMPARE_DIKPQ_H
#define SPA_COMPARE_DIKPQ_H

#include <queue>
#include "../map/Maze.h"
#include "SPAInterface.h"


class DIKPQ : public SPAInterface{
private:

    Maze maze;

    // The starting point and destination of route.
    Location start, end;

    // Distance table that stores shortest distance of all locations(vertices).
    int DistTable[MAX_COLUMN][MAX_ROW];

    // Priority Queue of adjacent locations to found set.
    std::priority_queue<std::pair<int,Location*>> adjacentLocQueue;

    // Update distance of new adjacent location only.
    void UpdateDist( Location *currentLoc);

public:
    DIKPQ();
    void setMaze(const Maze &mazeInput) override;
    void setStart(int row, int column) override;
    void setDestination(int row, int column) override;
    void FindSP() override;
    int getShortestPathLength() override;
    std::string getTypeName() override;
    void printLocationDistSet();
};

#endif //SPA_COMPARE_DIKPQ_H
