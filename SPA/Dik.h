//
// Created by 김태현 on 2021/07/07.
//

#ifndef SPA_COMPARE_DIK_H
#define SPA_COMPARE_DIK_H

#include <set>
#include "map/Maze.h"
#include "spa_interface.h"
#include "structure/PathTree.h"

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
    int spendedTime;


    std::vector<Location*> foundLocationSet;

    /*
     * Tree that stores paths for all visited vertices.
     */
    PathTree pathTree;


    bool isLocationInSet(Location *location);

public:
    DIK();
    void setMaze(const Maze &mazeInput) override;
    void setStart(int row, int column) override;
    void setDestination(int row, int column) override;
    void FindSP() override;
    int getSPDist()  override;
    int getSpendedTime() override;
};

#endif //SPA_COMPARE_DIK_H
