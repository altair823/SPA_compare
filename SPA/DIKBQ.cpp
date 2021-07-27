//
// Created by 김태현 on 2021/07/27.
//

#include "DIKBQ.h"

DIKBQ::DIKBQ() {
    for (auto & column : DistTable) {
        for (auto & row : column) {
            row.first = INF;
            row.second = nullptr;
        }
    }
    adjacentLocQueue.setKeyMaker(makeIndex);
}

void DIKBQ::setMaze(Maze &mazeInput) {
    maze = &mazeInput;
}

void DIKBQ::setStart(int row, int column) {
    if (row < 0 || row >= MAX_ROW || column < 0 || column >= MAX_COLUMN){
        std::cout << "Wrong Starting Point input in "<< getTypeName() << std::endl;
        exit(2);
    }
    start = maze->getLocation(row, column);
}

void DIKBQ::setEnd(int row, int column) {
    if (row < 0 || row >= MAX_ROW || column < 0 || column >= MAX_COLUMN){
        std::cout<<"Wrong Ending Point input in "<<getTypeName()<<std::endl;
        exit(2);
    }
    end = maze->getLocation(row, column);
}

void DIKBQ::FindSP() {

    DistTable[start->getColumn()][start->getRow()].first = 0;
    DistTable[start->getColumn()][start->getRow()].second = nullptr;


    // Initially push the starting point to PQ.
    adjacentLocQueue.Insert(0, *start);

    Location *currentLoc = start;

    // Loop until reached the ending point.
    while (currentLoc->getRow() != end->getRow() || currentLoc->getColumn() != end->getColumn()){

        // Dequeue the closest location.
        // The distance of location from the starting point is used for only sorting.
        int currentDist = adjacentLocQueue.getMinimumKey();
        currentLoc = adjacentLocQueue.PopMinimum();
        if (DistTable[currentLoc->getColumn()][currentLoc->getRow()].first < currentDist){
            continue;
        }
        // Update distance table for adjacent locations.
        UpdateDist(currentLoc);
    }

    makeSPList();
}

void DIKBQ::UpdateDist(Location *currentLoc) {
    for (int dir = 0; dir < 4; ++dir) {
        Location* adjacent = currentLoc->getAdjacent(dir);
        // If there is adjacent location exists,
        // and its new distance is shorter then distance in the table, update it.
        if (adjacent != nullptr &&
            DistTable[adjacent->getColumn()][adjacent->getRow()].first >
            currentLoc->getWeight(dir) + DistTable[currentLoc->getColumn()][currentLoc->getRow()].first) {

            DistTable[adjacent->getColumn()][adjacent->getRow()].first =
                    currentLoc->getWeight(dir) + DistTable[currentLoc->getColumn()][currentLoc->getRow()].first;

            DistTable[adjacent->getColumn()][adjacent->getRow()].second =
                    currentLoc;

            // Enqueue the new adjacent location which is updated just before.
            adjacentLocQueue.Insert(
                    DistTable[adjacent->getColumn()][adjacent->getRow()].first,
                     *adjacent);
        }
    }
}

void DIKBQ::makeSPList() {
    // Store the shortest path locations to the list.
    Location *current = end;
    while (current->getRow() != start->getRow() || current->getColumn() != start->getColumn()){
        SPList.insert(SPList.begin(), current);
        current = DistTable[current->getColumn()][current->getRow()].second;
    }
    SPList.insert(SPList.begin(), current);
}

int DIKBQ::getShortestPathLength() const {
    return DistTable[end->getColumn()][end->getRow()].first;
}

std::vector<Location *> DIKBQ::getSPList() const {
    return SPList;
}

std::string DIKBQ::getTypeName() const {
    return std::string("DIKBQ ");
}

int DIKBQ::makeIndex(int &distance) {
    return distance;
}
