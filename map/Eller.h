//
// Created by κΉνν on 2021/07/08.
//
// This Maze making algorithm is based on Eller's algorithm.
// The reference I referred is hear, http://weblog.jamisbuck.org/2010/12/29/maze-generation-eller-s-algorithm
// Because it called only once when program start making maze,
// this class use the Set structure from STL though the performance may decrease.

#ifndef SPA_COMPARE_ELLER_H
#define SPA_COMPARE_ELLER_H

#include <set>
#include <vector>
#include "Maze.h"
#include <random>

class Eller{
private:
    Maze *tempMaze;

    int STD;

    std::set<int> existingSet;

    /*
     * Set that contains all cells. The integer number indicate the kind of set.
     * This is because, in the maximal situation, every cell is in a different set.
     * 0 means that cell is not in the set.
     */
    std::vector<int> locationSet;

    /*
     * The set act like temp buffer for next raw.
     * When setting of certain raw is over and vertical merging ended,
     * values in this set are copied to locationSet and going to initialize with 0.
     */
    std::vector<int> nextLocationSet;

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
     * Generates a single integer with a normal distribution.
     */
    int GenerateWeightND();

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

    /*
     * Update Sets that contains all cells in current row.
     * Change the cell's set value to destSetRow's value if it is targetSetRow's value.
     */
    void UpdateSet(int targetSetRow, int destSetRow);

public:
    explicit Eller(Maze &maze);
    /*
     * The function that creates complete maze based on Eller's algorithm.
     */
    void MakeMaze();

    /*
     * For debug. Print current location set values.
     */
    void printCurrentLocationSet();

    std::string getTypeString();
};

#endif //SPA_COMPARE_ELLER_H
