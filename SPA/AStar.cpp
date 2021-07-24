//
// Created by 김태현 on 2021/07/23.
//

#include "AStar.h"

AStar::AStar() {
    for (auto & column : DistTable) {
        for (auto & row : column) {
            std::get<0>(row) = INF;
            std::get<1>(row) = INF;
            std::get<2>(row) = nullptr;
        }
    }
}

void AStar::setMaze(const Maze &mazeInput) {
    maze = mazeInput;
}

void AStar::setStart(int row, int column) {
    if (row < 0 || row >= MAX_ROW || column < 0 || column >= MAX_COLUMN) {
        std::cout << "Wrong Starting Point input in "<< getTypeName() << std::endl;
        exit(2);
    }
    start = &maze[column][row];
}

void AStar::setEnd(int row, int column) {
    if (row < 0 || row >= MAX_ROW || column < 0 || column >= MAX_COLUMN){
        std::cout<<"Wrong Ending Point input in "<<getTypeName()<<std::endl;
        exit(2);
    }
    end = &maze[column][row];

}

void AStar::FindSP() {

    std::get<0>(DistTable[start->getColumn()][start->getRow()]) = 0;
    std::get<1>(DistTable[start->getColumn()][start->getRow()]) = EstimateDistToEnd(start);
    std::get<2>(DistTable[start->getColumn()][start->getRow()]) = nullptr;

    // Initially push the starting point to PQ.
    adjacentLocQueue.push({std::get<0>(DistTable[start->getColumn()][start->getRow()]) + std::get<1>(DistTable[start->getColumn()][start->getRow()]), start});

    Location* currentLoc = start;

    while (currentLoc->getRow() != end->getRow() || currentLoc->getColumn() != end->getColumn()){
        // Dequeue the closest location.
        int currentDist = -adjacentLocQueue.top().first;
        currentLoc = adjacentLocQueue.top().second;
        adjacentLocQueue.pop();

        // If that location is already founded, move to next adjacent location.
        if (std::get<0>(DistTable[currentLoc->getColumn()][currentLoc->getRow()]) < currentDist - std::get<1>(DistTable[currentLoc->getColumn()][currentLoc->getRow()])){
            continue;
        }
        UpdateDist(currentLoc);
    }
}

void AStar::UpdateDist(Location *currentLoc) {
    for (int dir = 0; dir < 4; ++dir) {
        // If there is adjacent location exists,
        // and its new distance is shorter then distance in the table, update it.
        if (currentLoc->getAdjacent(dir) != nullptr &&
            DistTable[currentLoc->getAdjacent(dir)->getColumn()][currentLoc->getAdjacent(dir)->getRow()].first >
            currentLoc->getWeight(dir) + DistTable[currentLoc->getColumn()][currentLoc->getRow()].first) {

            DistTable[currentLoc->getAdjacent(dir)->getColumn()][currentLoc->getAdjacent(dir)->getRow()].first =
                    currentLoc->getWeight(dir) + DistTable[currentLoc->getColumn()][currentLoc->getRow()].first;

            DistTable[currentLoc->getAdjacent(dir)->getColumn()][currentLoc->getAdjacent(dir)->getRow()].second =
                    currentLoc;

            // Enqueue the new adjacent location which is updated just before.
            adjacentLocQueue.push(
                    {-DistTable[currentLoc->getAdjacent(dir)->getColumn()][currentLoc->getAdjacent(dir)->getRow()].first,
                     currentLoc->getAdjacent(dir)});
        }
    }
}

int AStar::EstimateDistToEnd(Location *loc) {
    return int (sqrt(pow(double (end->getRow() - loc->getRow()), 2) + pow(double (end->getColumn() - loc->getColumn()), 2)));
}

int AStar::getShortestPathLength() const {
    return 0;
}

std::string AStar::getTypeName() const {
    return std::string("Astar ");
}


