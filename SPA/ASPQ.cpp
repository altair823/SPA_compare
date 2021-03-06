//
// Created by κΉνν on 2021/07/23.
//

#include "ASPQ.h"

ASPQ::ASPQ() {
    for (auto & column : DistTable) {
        for (auto & row : column) {
            row.first = INF;
            row.second = nullptr;
        }
    }
}

void ASPQ::setMaze(Maze &mazeInput) {
    maze = &mazeInput;
}

void ASPQ::setStart(int row, int column) {
    if (row < 0 || row >= MAX_ROW || column < 0 || column >= MAX_COLUMN) {
        std::cout << "Wrong Starting Point input in "<< getTypeName() << std::endl;
        exit(2);
    }
    start = maze->getLocation(row, column);
}

void ASPQ::setEnd(int row, int column) {
    if (row < 0 || row >= MAX_ROW || column < 0 || column >= MAX_COLUMN){
        std::cout<<"Wrong Ending Point input in "<<getTypeName()<<std::endl;
        exit(2);
    }
    end = maze->getLocation(row, column);

}

void ASPQ::FindSP() {

    DistTable[start->getColumn()][start->getRow()].first = 0;
    DistTable[start->getColumn()][start->getRow()].second = nullptr;

    // Initially push the starting point to PQ.
    adjacentLocQueue.push({-(DistTable[start->getColumn()][start->getRow()].first + distanceTable[start->getColumn()][start->getRow()]), start});

    Location* currentLoc = start;

    while (currentLoc->getRow() != end->getRow() || currentLoc->getColumn() != end->getColumn()){

        // Dequeue the closest location.
        // The distance of location from the starting point is used for only sorting.
        currentLoc = adjacentLocQueue.top().second;
        adjacentLocQueue.pop();

        // Update distance table for adjacent locations.
        UpdateDist(currentLoc);
    }
    makeSPList();
}

void ASPQ::UpdateDist(Location *currentLoc) {
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
                    {-(DistTable[adjacent->getColumn()][adjacent->getRow()].first + distanceTable[adjacent->getColumn()][adjacent->getRow()]),
                     adjacent});
        }
    }
}

void ASPQ::makeSPList() {
    // Store the shortest path locations to the list.
    Location *current = end;
    while (current->getRow() != start->getRow() || current->getColumn() != start->getColumn()){
        SPList.insert(SPList.begin(), current);
        current = DistTable[current->getColumn()][current->getRow()].second;
    }
    SPList.insert(SPList.begin(), current);
}

int ASPQ::EstimateDistToEnd(Location *loc) {
    int estimateDist = int (sqrt(pow(double (end->getRow()*10 - loc->getRow()*10), 2) + pow(double (end->getColumn()*10 - loc->getColumn()*10), 2)));
    return estimateDist;
}

int ASPQ::getShortestPathLength() const {
    return DistTable[end->getColumn()][end->getRow()].first;
}

std::string ASPQ::getTypeName() const {
    return std::string("ASPQ  ");
}

std::vector<Location *> ASPQ::getSPList() const {
    return SPList;
}
void ASPQ::printShortestPath() const {

    for (auto &loc : SPList) {
        std::cout<<*loc<<" | ";
    }
    std::cout<<std::endl;
}
void ASPQ::printLocationDistSet() const {
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

void ASPQ::makeDistTable() {

    for (int i = 0; i < MAX_COLUMN; i++) {
        for (int j = 0; j < MAX_ROW; j++) {
            if (maze->getStandardDeviation() != 0) {
                distanceTable[i][j] =
                        ((std::abs(end->getRow() - j)) * WEIGHT_MIN) +
                        ((std::abs(end->getColumn() - i)) * WEIGHT_MIN);
            } else {
                distanceTable[i][j] =
                        ((std::abs(end->getRow() - j)) * WEIGHT_MEAN) +
                        ((std::abs(end->getColumn() - i)) * WEIGHT_MEAN);
            }
        }
    }
}
