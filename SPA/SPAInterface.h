//
// Created by 김태현 on 2021/07/10.
//

#ifndef SPA_COMPARE_SPAINTERFACE_H
#define SPA_COMPARE_SPAINTERFACE_H

#include <map/Maze.h>

class SPAInterface{
public:
    // Copy the given maze.
    virtual void setMaze(const Maze &maze) = 0;

    // Set starting point.
    virtual void setStart(int row, int column) = 0;

    // Set ending point.
    virtual void setEnd(int row, int column) = 0;

    // Find shortest path.
    virtual void FindSP() = 0;

    // Get SP's length.
    virtual int getShortestPathLength() const = 0;

    // Get list of locations that make up the SP.
    virtual std::vector<Location*> getSPList() const = 0;

    // Get the class name of SPA object which indicate the algorithm type.
    virtual std::string getTypeName() const = 0;



    // For common debug.
    virtual void printLocationDistSet() const = 0;
    virtual void printShortestPath() const = 0;
};

#endif //SPA_COMPARE_SPAINTERFACE_H
