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

    // Distance table that stores shortest distance of all locations and their previous location.
    std::pair<int, Location*> DistTable[MAX_COLUMN][MAX_ROW];

    // Priority Queue of adjacent locations to found set.
    std::priority_queue<std::pair<int,Location*>> adjacentLocQueue;

    // A list of locations in shortest path.
    std::vector<Location*> SPList;

    // Update distance of new adjacent location only.
    void UpdateDist( Location *currentLoc);
    void makeSPList();

public:
    DIKPQ();
    void setMaze(const Maze &mazeInput) override;
    void setStart(int row, int column) override;
    void setEnd(int row, int column) override;
    void FindSP() override;
    int getShortestPathLength() const override;
    std::vector<Location*> getSPList() const override;
    std::string getTypeName() const override;
    void printLocationDistSet() const;
    void printShortestPath() const;
};

#endif //SPA_COMPARE_DIKPQ_H
