//
// Created by 김태현 on 2021/07/22.
//

#include "CompareSP.h"

void CompareSP::InsertSP(SPAInterface *algorithm, std::chrono::duration<double> timeSpandMs) {
    SPAList.emplace_back(algorithm, timeSpandMs);
}

std::string CompareSP::getAllSPAResult() {
    std::string allResult;
    for (auto &result : SPAList) {
        allResult.append(result.first->getTypeName()).append("'s SP length : ").append(std::to_string(result.first->getShortestPathLength())).append(" - Execution time is : ").append(std::to_string(result.second.count())).append("\n");
    }
    return allResult;
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

void CompareSP::SaveDataFiles() {
    std::ofstream timeResultFile;
    timeResultFile.open("time_result.txt", std::ios::app);
    timeResultFile << "[Round: " << round << "]" << std::endl;

    timeResultFile << getAllSPAResult() << std::endl;
    timeResultFile.close();
}

void CompareSP::InitializeResultFile() {
    std::filesystem::path resultFile(RESULT_FILE_NAME);
    if (std::filesystem::exists(resultFile)){
        if (std::filesystem::is_regular_file(resultFile)){
            std::filesystem::remove(resultFile);
        } else{
            std::filesystem::remove_all(resultFile);
        }
    }
}

void CompareSP::InitializeResultData() {
    SPAList.clear();
}

void CompareSP::setRoundNum(int newRound) {
    round = newRound;
}
