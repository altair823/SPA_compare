//
// Created by 김태현 on 2021/07/10.
//

#ifndef SPA_COMPARE_SPAINTERFACE_H
#define SPA_COMPARE_SPAINTERFACE_H

class SpaInterface{
    virtual void setMaze(const Maze &maze) = 0;
    virtual void setStart(int row, int column) = 0;
    virtual void setDestination(int row, int column) = 0;
    virtual void FindSP() = 0;
    virtual int getSPDist() = 0;
    virtual int getSpendedTime() = 0;
};

#endif //SPA_COMPARE_SPAINTERFACE_H
