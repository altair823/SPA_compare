//
// Created by 김태현 on 2021/07/07.
//

#ifndef SPA_COMPARE_MAZE_H
#define SPA_COMPARE_MAZE_H

#include "declaration.h"
#include "location.h"
#include <iostream>
#include <cstdarg>

/*
 * Maze that need to found the SP by SPA.
 * There could be multiple SP or none.
 */
class Maze{
private:
    Location location[MAX_COLUMN][MAX_RAW]{};

public:
    Maze();
    /*
     * Return particular location object based on Cartesian coordinate.
     */
    Location getLocation(int x, int y) const;
    /*
     * Operator overload for getting the location object.
     */
    Location * operator[] (int idx);
    const Location * operator[] (int idx) const;
    /*
     * Print all maze cell's direction flags.
     */
    void PrintMaze() const;

};

#endif //SPA_COMPARE_MAZE_H
