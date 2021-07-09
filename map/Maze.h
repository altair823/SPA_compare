//
// Created by 김태현 on 2021/07/07.
//

#ifndef SPA_COMPARE_MAZE_H
#define SPA_COMPARE_MAZE_H

#include "declaration.h"
#include "Location.h"
#include <iostream>
#include <cstdarg>
#include <fstream>

/*
 * Maze that need to found the SP by SPA.
 * There could be multiple SP, but cannot be absent.
 */
class Maze{
private:
    Location location[MAX_COLUMN][MAX_ROW]{};

    /*
     * The number of previously created maze.
     */
    int mazeNumber;


public:
    Maze();
    Maze(const Maze&) = delete;

    void InitializeMaze();

    void IncreaseMazeNumber();

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
     * Open the wall.
     */
    void OpenWall(int row, int column, int direction);

    /*
     * Save all maze data in file for logging.
     */
    void SaveMazeFile();
};

#endif //SPA_COMPARE_MAZE_H
