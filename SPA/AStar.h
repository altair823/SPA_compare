//
// Created by 김태현 on 2021/07/23.
//

#ifndef SPA_COMPARE_ASTAR_H
#define SPA_COMPARE_ASTAR_H

#include <queue>
#include <tuple>
#include <cmath>
#include <cstdlib>
#include "SPAInterface.h"
#include "../map/Maze.h"

class AStar : public SPAInterface{
private:
    Maze *maze;

    // Distance table that stores shortest distance of all locations and their previous location.
    std::pair<int, Location*> DistTable[MAX_COLUMN][MAX_ROW];

    // Priority Queue of adjacent locations to found set.
    // The int values indicate distance between current location and adjacent location +
    // estimated distance between adjacent location and destination.
    std::priority_queue<std::pair<int, Location*>> adjacentLocQueue;

    // Update distance of new adjacent location only.
    void UpdateDist( Location *currentLoc);

    // Estimate the distance between given location and destination.
    int EstimateDistToEnd(Location* loc);
    void makeSPList();

    int distanceTable[MAX_COLUMN][MAX_ROW];
public:
    AStar();
    void setMaze(Maze &maze) override;
    void setStart(int row, int column) override;
    void setEnd(int row, int column) override;
    void FindSP() override;
    int getShortestPathLength() const override;
    std::vector<Location*> getSPList() const override;
    std::string getTypeName() const override;
    void printShortestPath() const;
    void printLocationDistSet() const;
    void makeDistTable();
};

#endif //SPA_COMPARE_ASTAR_H
