//
// Created by κΉνν on 2021/07/27.
//

#ifndef SPA_COMPARE_ASBQ_H
#define SPA_COMPARE_ASBQ_H

#include "../structure/BucketQueue.h"
#include <cmath>
#include <cstdlib>
#include "SPAInterface.h"
#include "../map/Maze.h"

class ASBQ : public SPAInterface{
private:
    int maxWeight = 0;
    Maze *maze;

    // Distance table that stores shortest distance of all locations and their previous location.
    std::pair<int, Location*> DistTable[MAX_COLUMN][MAX_ROW];

    // Priority Queue of adjacent locations to found set.
    // The int values indicate distance between current location and adjacent location +
    // estimated distance between adjacent location and destination.
    BucketQueue<int, Location> adjacentLocQueue;

    // Update distance of new adjacent location only.
    void UpdateDist( Location *currentLoc);

    // Estimate the distance between given location and destination.
    int EstimateDistToEnd(Location* loc);
    void makeSPList();

    int distanceTable[MAX_COLUMN][MAX_ROW]{};
public:
    ASBQ();
    void setMaze(Maze &maze) override;
    void setStart(int row, int column) override;
    void setEnd(int row, int column) override;
    void FindSP() override;
    int getShortestPathLength() const override;
    std::vector<Location*> getSPList() const override;
    std::string getTypeName() const override;
    void printShortestPath() const;
    void printLocationDistSet() const;
    void makeDistTable() override;
};

#endif //SPA_COMPARE_ASBQ_H
