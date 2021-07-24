//
// Created by 김태현 on 2021/07/22.
//

#include "CompareSP.h"

void CompareSP::InsertSP(SPAInterface *algorithm, std::chrono::duration<double> timeSpandMs) {
    SPAList.emplace_back(algorithm, timeSpandMs);
}

void CompareSP::PrintAllSPAResult() {
    for (auto &result : SPAList) {
        std::cout<<result.first->getTypeName()<<"'s SP length : "<<result.first->getShortestPathLength()<<
        " - Execution time is : "<<result.second.count()<<std::endl;
    }
}

void CompareSP::CompareAllSPList() {
    bool isSame = false;
    Location temp;
    for (auto &spa : SPAList) {
        std::cout<<spa.first->getTypeName();
    }
    std::cout<<std::endl;

    for (int locNum = 0; ; locNum++) {
        for (int spaNum = 0; spaNum < SPAList.size(); ++spaNum) {
            if (SPAList[spaNum].first->getSPList().size() <= locNum){
                return;
            }
            Location *currentLoc = SPAList[spaNum].first->getSPList()[locNum];
            if (spaNum == 0){
                isSame = true;
                temp.setRow(currentLoc->getRow());
                temp.setColumn(currentLoc->getColumn());
            } else if (temp.getRow() != currentLoc->getRow() || temp.getColumn() != currentLoc->getColumn()){
                isSame = false;
            }

            if (isSame){
                std::cout<<"*     ";
            } else{
                std::cout<<"!     ";
            }
        }
        std::cout<<std::endl;
    }
}
