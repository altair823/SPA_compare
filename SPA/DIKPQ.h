//
// Created by 김태현 on 2021/07/15.
//

#ifndef SPA_COMPARE_DIKPQ_H
#define SPA_COMPARE_DIKPQ_H

#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#include "../map/Maze.h"
#include "spa_interface.h"


class DIKPQ : public SpaInterface{
private:

    Maze maze;

    /*
     * The starting point and destination of route.
     */
    Location start, end;


    int locationDistSet[MAX_COLUMN][MAX_ROW];

    std::vector<Location> foundLocationSet;

    // Vector of adjacent locations to found set.
    std::vector<Location> adjacentSet;

    bool cmp(Location loc1, Location loc2);




    void UpdateDist();

public:
    DIKPQ();
    void setMaze(const Maze &mazeInput) override;
    void setStart(int row, int column) override;
    void setDestination(int row, int column) override;
    void FindSP() override;
};

#endif //SPA_COMPARE_DIKPQ_H
