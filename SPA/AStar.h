//
// Created by 김태현 on 2021/07/23.
//

#ifndef SPA_COMPARE_ASTAR_H
#define SPA_COMPARE_ASTAR_H

#include "SPAInterface.h"
#include "../map/Maze.h"

class AStar : public SPAInterface{
private:
    Maze maze;

    // The starting point and destination of route.
    Location start, end;


public:
    void setMaze(const Maze &maze) override;
    void setStart(int row, int column) override;
    void setDestination(int row, int column) override;
    void FindSP() override;
    //int getShortestPathLength() override;
    //std::string getTypeName() override;
};

#endif //SPA_COMPARE_ASTAR_H
