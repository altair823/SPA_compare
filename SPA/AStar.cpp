//
// Created by 김태현 on 2021/07/23.
//

#include "AStar.h"

AStar::AStar() {
    for (auto & column : DistTable) {
        for (auto & row : column) {
            row.first = INF;
            row.second = nullptr;
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

void AStar::UpdateDist(Location *currentLoc) {
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

void AStar::makeSPList() {
    // Store the shortest path locations to the list.
    Location *current = end;
    while (current->getRow() != start->getRow() || current->getColumn() != start->getColumn()){
        SPList.insert(SPList.begin(), current);
        current = DistTable[current->getColumn()][current->getRow()].second;
    }
    SPList.insert(SPList.begin(), current);
}

int AStar::EstimateDistToEnd(Location *loc) {
    int estimateDist = int (sqrt(pow(double (end->getRow()*10 - loc->getRow()*10), 2) + pow(double (end->getColumn()*10 - loc->getColumn()*10), 2)));
    return estimateDist;
}

int AStar::getShortestPathLength() const {
    return DistTable[end->getColumn()][end->getRow()].first;
}

std::string AStar::getTypeName() const {
    return std::string("Astar ");
}

std::vector<Location *> AStar::getSPList() const {
    return SPList;
}
void AStar::printShortestPath() const {

    for (auto &loc : SPList) {
        std::cout<<*loc<<" | ";
    }
    std::cout<<std::endl;
}
void AStar::printLocationDistSet() const {
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

void AStar::makeDistTable() {

    for (int i = 0; i < MAX_COLUMN; i++) {
        for (int j = 0; j < MAX_ROW; j++) {
            //distanceTable[i][j] = int (sqrt(pow(double (end->getRow()*ASTAR_DIST_WEIGHT - j*ASTAR_DIST_WEIGHT), 2) +
            //        pow(double (end->getColumn()*ASTAR_DIST_WEIGHT - i*ASTAR_DIST_WEIGHT), 2)));
            distanceTable[i][j] = std::abs(end->getRow() - j)*ASTAR_DIST_WEIGHT + std::abs(end->getColumn() - i)*ASTAR_DIST_WEIGHT;
        }
    }
}
