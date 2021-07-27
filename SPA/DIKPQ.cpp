//
// Created by 김태현 on 2021/07/15.
//

#include "DIKPQ.h"

DIKPQ::DIKPQ() {
    for (auto & column : DistTable) {
        for (auto & row : column) {
            row.first = INF;
            row.second = nullptr;
        }
    }
}

void DIKPQ::setMaze(Maze &mazeInput) {
    maze = &mazeInput;
}

void DIKPQ::setStart(int row, int column) {
    if (row < 0 || row >= MAX_ROW || column < 0 || column >= MAX_COLUMN){
        std::cout << "Wrong Starting Point input in "<< getTypeName() << std::endl;
        exit(2);
    }
    start = maze->getLocation(row, column);
}

void DIKPQ::setEnd(int row, int column) {
    if (row < 0 || row >= MAX_ROW || column < 0 || column >= MAX_COLUMN){
        std::cout<<"Wrong Ending Point input in "<<getTypeName()<<std::endl;
        exit(2);
    }
    end = maze->getLocation(row, column);
}

void DIKPQ::FindSP() {

    DistTable[start->getColumn()][start->getRow()].first = 0;
    DistTable[start->getColumn()][start->getRow()].second = nullptr;


    // Initially push the starting point to PQ.
    adjacentLocQueue.push({0, start});

    Location *currentLoc = start;

    // Loop until reached the ending point.
    while (currentLoc->getRow() != end->getRow() || currentLoc->getColumn() != end->getColumn()){

        // Dequeue the closest location.
        // The distance of location from the starting point is used for only sorting.
        int currentDist = adjacentLocQueue.top().first;
        currentLoc = adjacentLocQueue.top().second;
        adjacentLocQueue.pop();
        if (DistTable[currentLoc->getColumn()][currentLoc->getRow()].first < currentDist){
            continue;
        }
        // Update distance table for adjacent locations.
        UpdateDist(currentLoc);
    }

    makeSPList();
}

void DIKPQ::UpdateDist(Location *currentLoc) {
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
            adjacentLocQueue.push(
                    {-DistTable[adjacent->getColumn()][adjacent->getRow()].first,
                     adjacent});
        }
    }
}

void DIKPQ::makeSPList() {
    // Store the shortest path locations to the list.
    Location *current = end;
    while (current->getRow() != start->getRow() || current->getColumn() != start->getColumn()){
        SPList.insert(SPList.begin(), current);
        current = DistTable[current->getColumn()][current->getRow()].second;
    }
    SPList.insert(SPList.begin(), current);
}

void DIKPQ::printLocationDistSet() const {
    for (auto & column : DistTable) {
        for (auto & row : column) {
            if (row.first != INF) {
                std::cout <<  "0 ";
            } else{
                std::cout <<  "- ";
            }
        }
        std::cout<<std::endl;
    }
}

int DIKPQ::getShortestPathLength() const {
    return DistTable[end->getColumn()][end->getRow()].first;
}

std::string DIKPQ::getTypeName() const {
    return std::string("DIKPQ ");
}

void DIKPQ::printShortestPath() const {

    for (auto &loc : SPList) {
        std::cout<<*loc<<" | ";
    }
    std::cout<<std::endl;
}

std::vector<Location *> DIKPQ::getSPList() const {
    return SPList;
}


