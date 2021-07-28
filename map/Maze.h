//
// Created by 김태현 on 2021/07/07.
//

#ifndef SPA_COMPARE_MAZE_H
#define SPA_COMPARE_MAZE_H

#include "../declaration.h"
#include "Location.h"
#include <iostream>
#include <fstream>

/*
 * Maze that need to found the SP by SPA.
 * There could be multiple SP, but cannot be absent.
 */
class Maze{
private:

    int maxRow, maxColumn;
    Location location[MAX_COLUMN][MAX_ROW];
    int standardDeviation;

public:
    Maze(int maxRow, int maxColumn, int stdInput);
    Maze(const Maze&) = delete;
    int getRowSize();
    int getColumnSize();
    Location* getLocation(int row, int column);
    int getStandardDeviation() const;

    void InitializeMaze();

    void ConnectAdjacentLoc(int row, int column);


    /*
     * Operator overload for getting the location object.
     */
    Location * operator[] (int idx);
    const Location * operator[] (int idx) const;

    /*
     * Print all maze cell's direction flags.
     */
    void PrintMaze() const;

    /*
     * Open the sidewall of given location.
     * The direction and its weight are also given.
     */
    void OpenWall(int row, int column, int direction, int weight);
};

#endif //SPA_COMPARE_MAZE_H
