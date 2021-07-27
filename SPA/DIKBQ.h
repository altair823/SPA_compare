//
// Created by 김태현 on 2021/07/27.
//

#ifndef SPA_COMPARE_DIKBQ_H
#define SPA_COMPARE_DIKBQ_H

#include "../structure/BucketQueue.h"
#include "../map/Maze.h"
#include "SPAInterface.h"


class DIKBQ : public SPAInterface{
private:
    Maze *maze;

    // Distance table that stores shortest distance of all locations and their previous location.
    std::pair<int, Location*> DistTable[MAX_COLUMN][MAX_ROW];

    // Priority Queue of adjacent locations to found set.
    BucketQueue<int, Location> adjacentLocQueue;

    // A list of locations in shortest path.
    std::vector<Location*> SPList;

    // Update distance of new adjacent location only.
    void UpdateDist( Location *currentLoc);
    void makeSPList();

    // Function that makes key to array index.
    static int makeIndex(int &distance);

public:
    DIKBQ();
    void setMaze(Maze &mazeInput) override;
    void setStart(int row, int column) override;
    void setEnd(int row, int column) override;
    void FindSP() override;
    int getShortestPathLength() const override;
    std::vector<Location*> getSPList() const override;
    std::string getTypeName() const override;
};

#endif //SPA_COMPARE_DIKBQ_H
