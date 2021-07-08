//
// Created by 김태현 on 2021/07/08.
//
// This Maze making algorithm is based on Eller's algorithm.
// The reference I referred is hear, http://weblog.jamisbuck.org/2010/12/29/maze-generation-eller-s-algorithm
// Because it called only once when program start making maze,
// this class use the Set structure from STL though the performance may decrease.

#ifndef SPA_COMPARE_ELLER_H
#define SPA_COMPARE_ELLER_H

#include <set>
#include "maze.h"
#include <random>

class Eller{
private:
    // Set that contains all cells. The integer number indicate the kind of set.
    // This is because, in the maximal situation, every cell is in a different set.
    int locationSet[MAX_COLUMN][MAX_RAW] = {0, };

public:
    /*
     * The function that creates complete maze based on Eller's algorithm.
     */
    void MakeMaze(Maze &maze);

    /*
     * Returns a value for choosing whether to MergeWithRight or not.
     */
    bool ChoiceRandomly();

    /*
     * The function that MergeWithRight different sets.
     * The action merging two adjacent cells
     */
    void MergeWithRight(int x);
};

#endif //SPA_COMPARE_ELLER_H
