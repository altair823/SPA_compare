//
// Created by 김태현 on 2021/07/15.
//

#include "DIKPQ.h"

DIKPQ::DIKPQ() {
    for (auto & column : locationDistSet) {
        for (int & row : column) {
            row = INF;
        }
    }
}

void DIKPQ::setMaze(const Maze &mazeInput) {
    maze = mazeInput;
}

void DIKPQ::setStart(int row, int column) {
    if (row < 0 || row >= MAX_ROW || column < 0 || column >= MAX_COLUMN){
        std::cout<<"Wrong Starting Point!"<<std::endl;
        exit(2);
    }
    start = maze[column][row];
}

void DIKPQ::setDestination(int row, int column) {
    if (row < 0 || row >= MAX_ROW || column < 0 || column >= MAX_COLUMN){
        std::cout<<"Wrong Ending Point!"<<std::endl;
        exit(2);
    }
    end = maze[column][row];
}

void DIKPQ::FindSP() {
    // Insert starting point to found set.
    foundLocationSet.push_back(&start);

    locationDistSet[start.getYCoord()][start.getXCoord()] = 0;

    // Initially push the starting point to PQ.
    priorityQueue.push({0, &start});

    Location *closestLocation = &start;

    while (closestLocation->getXCoord() != end.getXCoord() || closestLocation->getYCoord() != end.getYCoord()){

        int dist = -priorityQueue.top().first;
        closestLocation = priorityQueue.top().second;
        priorityQueue.pop();

        if (locationDistSet[closestLocation->getYCoord()][closestLocation->getXCoord()] < dist){
            continue;
        }

        for (int dir = 0; dir < 4; ++dir) {
            if (closestLocation->getAdjacent(dir) != nullptr && // If there is adjacent location exists,
            locationDistSet[closestLocation->getAdjacent(dir)->getYCoord()][closestLocation->getAdjacent(dir)->getXCoord()] >
            closestLocation->getWeight(dir) + locationDistSet[closestLocation->getYCoord()][closestLocation->getXCoord()]){ // and its new distance is shorter then
                //the distance in table, update it.

                locationDistSet[closestLocation->getAdjacent(dir)->getYCoord()][closestLocation->getAdjacent(dir)->getXCoord()] =
                        closestLocation->getWeight(dir) + locationDistSet[closestLocation->getYCoord()][closestLocation->getXCoord()];

                priorityQueue.push({-locationDistSet[closestLocation->getAdjacent(dir)->getYCoord()][closestLocation->getAdjacent(dir)->getXCoord()], closestLocation->getAdjacent(dir)});

            }
        }
    }
}


void DIKPQ::printLocationDistSet() {
    for (auto & column : locationDistSet) {
        for (auto & row : column) {
            std::cout<<row<<" ";
        }
        std::cout<<std::endl;
    }
}

