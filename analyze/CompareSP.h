//
// Created by 김태현 on 2021/07/22.
//

#ifndef SPA_COMPARE_COMPARESP_H
#define SPA_COMPARE_COMPARESP_H

#include <vector>
#include <typeinfo>
#include <iostream>
#include "../SPA/SPAInterface.h"

class CompareSP{
private:
    std::vector<std::pair<int, std::string>> shortestPathList;

public:
    void insertSP(SPAInterface &algorithm);
    void printAllSPAResult();
};

#endif //SPA_COMPARE_COMPARESP_H
