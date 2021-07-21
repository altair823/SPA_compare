//
// Created by 김태현 on 2021/07/22.
//

#ifndef SPA_COMPARE_TIMEMEASURE_H
#define SPA_COMPARE_TIMEMEASURE_H

#include <chrono>
#include <iostream>

class TimeMeasure{

private:
    std::chrono::system_clock::time_point start;
    std::chrono::duration<double> duration;

public:
    void SetStart();
    void SetEnd();
    void PrintTimeMs();

};

#endif //SPA_COMPARE_TIMEMEASURE_H
