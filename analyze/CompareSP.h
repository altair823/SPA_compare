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
#include <fstream>
#include <filesystem>
#include "../SPA/SPAInterface.h"

class CompareSP{
private:
    std::vector<std::pair<SPAInterface*, std::chrono::duration<double>>> SPAList;
    int round;

public:
    // Initialize result data.
    void InitializeResultData();

    // Initialize result data files.
    void InitializeResultFile();

    void setRoundNum(int newRound);

    // Input new SPA.
    void InsertSP(SPAInterface *algorithm, std::chrono::duration<double> timeSpandMs);

    // Get all SPA searching result.
    std::string getAllSPAResult();

    // Compare all SPAs with its result.
    void CompareAllSPList();

    // Save result data to files.
    void SaveDataFiles();
};

#endif //SPA_COMPARE_COMPARESP_H
