//
// Created by 김태현 on 2021/07/07.
//

#include "Dik.h"


void DIK::setMaze(const Maze &mazeInput) {
    maze = mazeInput;
    SPDist = 0;
}

void DIK::setStart(int row, int column) {
    start = Location(row, column);
}

void DIK::setDestination(int row, int column) {
    end = Location(row, column);
}

void DIK::FindSP() {
    // Insert starting point to found set.
    foundLocationSet.push_back(&start);

    // Insert starting point to path tree.
    pathTree.InsertLocation(nullptr, &start, 0);

    for (int i = 0; i < foundLocationSet.size(); i++){
        for (int j = 0; j < MAX_EDGE_COUNT; j++){
            if (isLocationInSet(foundLocationSet[i].))
        }
    }
}

int DIK::getSPDist() {
    return SPDist;
}

int DIK::getSpendedTime() {
    return 0;
}

bool DIK::isLocationInSet(Location *location) {
    for (auto & i : foundLocationSet) {
        if (location == i){
            return true;
        }
    }
    return false;
}

