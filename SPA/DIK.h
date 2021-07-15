//
// Created by 김태현 on 2021/07/07.
//

#ifndef SPA_COMPARE_DIK_H
#define SPA_COMPARE_DIK_H

#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#include "../map/Maze.h"
#include "spa_interface.h"

class DIK : public SpaInterface{
private:

    Maze maze;

    /*
     * The starting point and destination of route.
     */
    Location start, end;

    /*
     * Distance of the found SP.
     */
    int SPDist;

    /*
     *
     */

    int locationDistSet[MAX_COLUMN][MAX_ROW];

    std::vector<Location> foundLocationSet;

    // Vector of adjacent locations to found set.
    std::vector<Location> adjacentSet;


    void UpdateDist();

public:
    DIK();
    void setMaze(const Maze &mazeInput) override;
    void setStart(int row, int column) override;
    void setDestination(int row, int column) override;
    void FindSP() override;
    void printLocationDistSet();


};



#endif //SPA_COMPARE_DIK_H
