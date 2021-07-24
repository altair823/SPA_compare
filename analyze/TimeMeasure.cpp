//
// Created by 김태현 on 2021/07/22.
//

#include "TimeMeasure.h"

void TimeMeasure::SetStart() {
    this->start = std::chrono::system_clock::now();
}

void TimeMeasure::SetEnd() {
    this->duration = std::chrono::system_clock::now() - start;
}

void TimeMeasure::PrintTimeMs(std::string SPAType) {
    std::cout<<"Execution times of "<<SPAType<<" are as follows: "<< this->duration.count()<<" second"<<std::endl;
}

std::chrono::duration<double> TimeMeasure::getTimeMs() {
    return this->duration;
}
