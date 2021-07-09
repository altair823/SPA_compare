//
// Created by 김태현 on 2021/07/10.
//

#ifndef SPA_COMPARE_SPAINTERFACE_H
#define SPA_COMPARE_SPAINTERFACE_H

class SpaInterface{
    virtual void SetMaze(const Maze &maze) = 0
    virtual void FindSP() = 0;
    virtual int GetSPDist() = 0;
};

#endif //SPA_COMPARE_SPAINTERFACE_H
