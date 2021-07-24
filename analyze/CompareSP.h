//
// Created by 김태현 on 2021/07/22.
//

#ifndef SPA_COMPARE_COMPARESP_H
#define SPA_COMPARE_COMPARESP_H

#include <vector>
#include <typeinfo>
#include <iostream>
#include <tuple>
#include <chrono>
#include "../SPA/SPAInterface.h"

class CompareSP{
private:
    std::vector<std::pair<SPAInterface*, std::chrono::duration<double>>> SPAList;

public:
    void InsertSP(SPAInterface *algorithm, std::chrono::duration<double> timeSpandMs);
    void PrintAllSPAResult();
    void CompareAllSPList();
};

#endif //SPA_COMPARE_COMPARESP_H
