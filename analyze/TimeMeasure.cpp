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

void TimeMeasure::PrintTimeMs() {
    std::cout<<"Execution times are as follows: "<< this->duration.count()<<" second"<<std::endl;
}
