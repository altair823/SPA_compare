//
// Created by 김태현 on 2021/07/22.
//

#include "CompareSP.h"

void CompareSP::insertSP(SPAInterface &algorithm) {
    std::string algorithmType = algorithm.getTypeName();
    shortestPathList.emplace_back(algorithm.getShortestPathLength(), algorithmType);
}

void CompareSP::printAllSPAResult() {
    for (auto &result : shortestPathList) {
        std::cout<<result.second<<"'s SP length : "<<result.first<<std::endl;
    }
}
