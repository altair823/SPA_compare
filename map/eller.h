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
    Maze* tempMaze;

    // Set that contains all cells. The integer number indicate the kind of set.
    // This is because, in the maximal situation, every cell is in a different set.
    // 0 means that cell is not in the set.
    int locationSet[MAX_RAW] = {0, };

    // The set act like temp buffer for next raw.
    // When setting of certain raw is over and vertical merging ended,
    // values in this set are copied to locationSet and going to initialize with 0.
    int nextLocationSet[MAX_RAW] = {0, };

public:
    explicit Eller(Maze &maze);
    /*
     * The function that creates complete maze based on Eller's algorithm.
     */
    void MakeMaze();

    /*
     * Returns a value for choosing whether to MergeWithRight or not.
     */
    bool ChoiceRandomly();

    /*
     * The functions that merging with different sets.
     */
    void MergeWithRight(int raw, int column);
    void MergeWithDown(int raw, int column);

    /*
     * For debug.
     */
    void printCurrentLocationSet();
};

#endif //SPA_COMPARE_ELLER_H
