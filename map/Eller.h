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
#include "Maze.h"
#include <random>

class Eller{
private:
    Maze tempMaze;

    std::set<int> existingSet;

    /*
     * Set that contains all cells. The integer number indicate the kind of set.
     * This is because, in the maximal situation, every cell is in a different set.
     * 0 means that cell is not in the set.
     */
    int locationSet[MAX_ROW] = {0, };

    /*
     * The set act like temp buffer for next raw.
     * When setting of certain raw is over and vertical merging ended,
     * values in this set are copied to locationSet and going to initialize with 0.
     */
    int nextLocationSet[MAX_ROW] = {0, };

    /*
     * Indicate previous set number that assigned to a cell in a single cycle.
     */
    int previouslyAssignedSetNumber;

    /*
     * Merge adjacent cells randomly.
     */
    void MergeRandomly(int colomn);

    /*
     * Returns a value for choosing whether to MergeWithRight or not.
     */
    bool ChoiceRandomly();

    /*
     * Each sets must merge more then one vertical cell.
     */
    void ExpandSetsVertical(int column);

    /*
     * Assigns an unassigned cell in the current row.
     */
    void AssignCellsInRow();

    /*
     * Assigns a new cell to a set number that has not been assigned so far.
     */
    int getUnusedSetNumber();

    /*
     * The functions that merging with different sets.
     */
    void MergeWithRight(int row, int column);
    void MergeWithDown(int row, int column);
    void MergeWithDifferentSet(int column);

public:
    explicit Eller(const Maze &maze);
    /*
     * The function that creates complete maze based on Eller's algorithm.
     */
    void MakeMaze();


    /*
     * For debug. Print current location set values.
     */
    void printCurrentLocationSet();
};

#endif //SPA_COMPARE_ELLER_H
