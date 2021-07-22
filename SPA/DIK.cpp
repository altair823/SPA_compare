//
// Created by 김태현 on 2021/07/07.
//

#include "DIK.h"

DIK::DIK() {
    for (auto & column : DistTable) {
        for (int & row : column) {
            row = INF;
        }
    }
}

void DIK::setMaze(const Maze &mazeInput) {
    maze = mazeInput;
}

void DIK::setStart(int row, int column) {
    if (row < 0 || row >= MAX_ROW || column < 0 || column >= MAX_COLUMN){
        std::cout<<"Wrong Starting Point!"<<std::endl;
        exit(2);
    }
    start = maze[column][row];
}

void DIK::setDestination(int row, int column) {
    if (row < 0 || row >= MAX_ROW || column < 0 || column >= MAX_COLUMN){
        std::cout<<"Wrong Ending Point!"<<std::endl;
        exit(2);
    }
    end = maze[column][row];
}

void DIK::FindSP() {
    // Insert starting point to found set.
    foundLocationSet.push_back(start);

    DistTable[start.getColumn()][start.getRow()] = 0;

    Location closestLocation = start;
    int closestIndex = 0;

    while (closestLocation != end){
        // 1. Update the distance to all vertices adjacent to the found location set.
        UpdateDist();

        // 2. Find the vertex which has minimum distance.
        int minDist = INF;
        for (int i = 0; i < adjacentSet.size(); ++i) {
            if (DistTable[adjacentSet[i].getColumn()][adjacentSet[i].getRow()] < minDist){
                minDist = DistTable[adjacentSet[i].getColumn()][adjacentSet[i].getRow()];
                closestLocation = adjacentSet[i];
                closestIndex = i;
            }
        }

        // 3. Insert that minimum vertex to the found location set.
        foundLocationSet.push_back(closestLocation);

        // 4. Delete that minimum vertex from the adjacent location set.
        adjacentSet.erase(adjacentSet.begin() + closestIndex);
    }
}

void DIK::UpdateDist() {
    // There are ways to improve performance at this point.
    // Such as data structure of adjacent vertices set.
    for (auto foundLoc : foundLocationSet){
        for (int dir = 0; dir < 4; dir++){
            // For the adjacent foundLoc from all found locations,
            // if the adjacent foundLoc is not in the found foundLoc set,
            // calculate minimum distance and update if it is needed.
            // The edge vertices of maze are have nullptr for limits of maze size.
            // nullptr checking has to be the first.
            if ((foundLoc.getAdjacent(dir) != nullptr) &&
            std::find(foundLocationSet.begin(), foundLocationSet.end(), *foundLoc.getAdjacent(dir)) == foundLocationSet.end()){
                if (std::find(adjacentSet.begin(), adjacentSet.end(), *foundLoc.getAdjacent(dir)) == adjacentSet.end()) {
                    adjacentSet.push_back(*foundLoc.getAdjacent(dir));
                }
                if (DistTable[foundLoc.getAdjacent(dir)->getColumn()][foundLoc.getAdjacent(dir)->getRow()] >
                    DistTable[foundLoc.getColumn()][foundLoc.getRow()] + foundLoc.getWeight(dir)){
                    DistTable[foundLoc.getAdjacent(dir)->getColumn()][foundLoc.getAdjacent(dir)->getRow()] =
                            DistTable[foundLoc.getColumn()][foundLoc.getRow()] + foundLoc.getWeight(dir);
                }
            }
        }
    }
}


void DIK::printLocationDistSet() {
    for (auto & column : DistTable) {
        for (auto & row : column) {
            std::cout<<row<<" ";
        }
        std::cout<<std::endl;
    }
}

int DIK::getShortestPathLength() {
    return DistTable[end.getColumn()][end.getRow()];
}

std::string DIK::getTypeName() {
    return std::string("DIK");
}

