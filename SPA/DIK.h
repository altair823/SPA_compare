//
// Created by 김태현 on 2021/07/07.
//

#ifndef SPA_COMPARE_DIK_H
#define SPA_COMPARE_DIK_H

#include <algorithm>
#include <vector>
#include "../map/Maze.h"
#include "SPAInterface.h"

class DIK : public SPAInterface{
private:

    Maze maze;

    //The starting point and destination of route.
    Location start, end;

    std::pair<int, Location*> DistTable[MAX_COLUMN][MAX_ROW];

    std::vector<Location*> foundLocationSet;

    // Vector of adjacent locations to found set.
    std::vector<Location*> adjacentSet;

    // A list of locations that in shortest path.
    std::vector<Location*> SPList;

    // Update distance of all existing adjacent.
    void UpdateDist();

public:
    DIK();
    void setMaze(const Maze &mazeInput) override;
    void setStart(int row, int column) override;
    void setEnd(int row, int column) override;
    void FindSP() override;
    int getShortestPathLength() const override;
    std::vector<Location*> getSPList() const override;
    std::string getTypeName() const override;
    void printLocationDistSet() const override;
    void printShortestPath() const override;
};

#endif //SPA_COMPARE_DIK_H
