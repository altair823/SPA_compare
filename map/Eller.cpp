//
// Created by 김태현 on 2021/07/08.
//


#include "Eller.h"

void Eller::printCurrentLocationSet() {
    for (int i : locationSet) {
        std::cout<<i<< " ";
    }
    std::cout<<std::endl;
}

Eller::Eller(Maze &maze) {
    previouslyAssignedSetNumber = 0;
    tempMaze = &maze;
    locationSet.resize(tempMaze->getRowSize());
    nextLocationSet.resize(tempMaze->getRowSize());
}

void Eller::MakeMaze() {
    // Set maze number for logging.
    tempMaze->InitializeMaze();

    // Initial inserting. All cells in first row are inserted in different sets.
    for (int i = 0; i < tempMaze->getRowSize(); ++i) {
        locationSet[i] = i + 1;
    }

    for (int column = 0; column < tempMaze->getColumnSize(); ++column) {
        MergeRandomly(column);
        ExpandSetsVertical(column);
        AssignCellsInRow();
        // Last row, merge all cells that has different set value.
        if (column == tempMaze->getColumnSize() - 1){
            MergeWithDifferentSet(column);
        }
    }
}

void Eller::MergeRandomly(int column) {
    for (int row = 0; row < tempMaze->getRowSize(); ++row) {
        if (ChoiceRandomly()){
            MergeWithRight(row, column);
        }
    }
}


bool Eller::ChoiceRandomly() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> choice_int(0, 1);
    if (choice_int(gen) == 0){
        return false;
    } else{
        return true;
    }
}

int Eller::GenerateWeightND(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<double> weight_int(WEIGHT_MEAN, tempMaze->getStandardDeviation());
    int weight;
    // The Maximum weight is below (mean*2)
    do {
        weight = (int)std::round(weight_int(gen));
    } while (weight <= WEIGHT_MIN || weight >= WEIGHT_MAX);
    return weight;
}

void Eller::ExpandSetsVertical(int column) {
    existingSet.clear();
    int SetStart = 0;
    int SetEnd = 0;
    int currentSet = 0;
    while (true) {
        for (int row = SetStart; row < tempMaze->getRowSize(); ++row) {
            // If new set is detected,
            if (locationSet[row] != 0 && currentSet == 0){
                // set start point
                SetStart = row;
                currentSet = locationSet[row];
                existingSet.insert(currentSet);
                // delete set value because we don't need it anymore.
                locationSet[row] = 0;
                // If same set is detected,
            } else if (currentSet == locationSet[row]){
                // just delete it.
                locationSet[row] = 0;
                // If different set is detected,
            } else if (currentSet != locationSet[row]){
                // set end point before current row.
                SetEnd = row - 1;
                // But don't delete the set value.
                break;
            }
            if (row == tempMaze->getRowSize() - 1){
                SetEnd = row;
                break;
            }
        }

        std::random_device rd;
        std::mt19937 gen(rd());

        // Randomly generate the count of vertical expanding between 1 and the size of set.
        std::uniform_int_distribution<> expandCountGen(1, SetEnd - SetStart + 1);

        // Randomly generate the row value to expand vertically.
        std::uniform_int_distribution<> expandRowGen(SetStart, SetEnd);

        // For every count of vertical expanding,
        int expandCount = expandCountGen(gen);
        for (; expandCount > 0; expandCount--) {
            int expandRow = expandRowGen(gen);
            // If new generated row value is already used, generate again.
            // This can be the bottleneck.
            if (nextLocationSet[expandRow] == currentSet) {
                expandCount++;
                continue;
                // Else, expand vertically.
            } else {
                nextLocationSet[expandRow] = currentSet;

                // Also merge two vertical cells in the real maze.
                MergeWithDown(expandRow, column);
            }
        }
        // End point is reached to the maximum, end the loop.
        // And update locationSet to nextLocationSet.
        if (SetEnd == tempMaze->getRowSize() - 1) {
            for (int i = 0; i < tempMaze->getRowSize(); i++){
                locationSet[i] = nextLocationSet[i];
                nextLocationSet[i] = 0;
            }
            break;
        } else {
            SetStart = SetEnd + 1;
            currentSet = 0;
        }
    }
}

void Eller::AssignCellsInRow() {
    previouslyAssignedSetNumber = 0;
    for (int & locationSetValue : locationSet) {
        if (locationSetValue == 0){
            // Assign new set number to cell which does not have one.
            locationSetValue = getUnusedSetNumber();
        }
    }
}

void Eller::MergeWithRight(int row, int column) {
    // If the right side cell doesn't exist, do nothing.
    if (row + 1 >= tempMaze->getRowSize()){
        return;
    }
    // Groups two cells into the same set.
    UpdateSet(row + 1, row);

    // Open right side wall at the current cell.
    // This is accompanied by opening the left wall in the right cell.
    tempMaze->OpenWall(row, column, RIGHT, GenerateWeightND());
}

void Eller::MergeWithDown(int row, int column) {
    if (column + 1 >= tempMaze->getColumnSize()){
        return;
    }
    tempMaze->OpenWall(row, column, DOWN, GenerateWeightND());
}

void Eller::MergeWithDifferentSet(int column) {
    for (int row = 0; row < tempMaze->getRowSize() - 1; ++row) {
        if (locationSet[row] != locationSet[row + 1]){
            MergeWithRight(row, column);
        }
    }
}

void Eller::UpdateSet(int targetSetRow, int destSetRow) {
    int targetSetValue = locationSet[targetSetRow];
    int destSetValue = locationSet[destSetRow];
    for (int row = targetSetRow-1; row < tempMaze->getRowSize(); row++){
        if (locationSet[row] == targetSetValue){
            locationSet[row] = destSetValue;
        }
    }
}

int Eller::getUnusedSetNumber() {
    // The number of sets is cannot over the maximum number of horizontal cells.
    for (int i = previouslyAssignedSetNumber + 1; i < tempMaze->getRowSize() + 1; i++){
        // Find unused set number and assign it.
        if (existingSet.find(i) == existingSet.end()){
            previouslyAssignedSetNumber = i;
            return i;
        }
    }
    std::cout<<"Set number assigning error!"<<std::endl;
    exit(1);
}

std::string Eller::getTypeString() {
    return std::string("MazeMaking");
}





