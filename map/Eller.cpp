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
}

void Eller::MakeMaze() {
    // Set maze number for logging.
    tempMaze->IncreaseMazeNumber();
    tempMaze->InitializeMaze();

    // Initial inserting. All cells in first row are inserted in different sets.
    for (int i = 0; i < MAX_ROW; ++i) {
        locationSet[i] = i + 1;
    }

    for (int column = 0; column < MAX_COLUMN; ++column) {
        MergeRandomly(column);
        ExpandSetsVertical(column);
        AssignCellsInRow();
        // Last row, merge all cells that has different set value.
        if (column == MAX_COLUMN - 1){
            MergeWithDifferentSet(column);
        }
    }
    tempMaze->SaveMazeFile();
}

void Eller::MergeRandomly(int column) {
    for (int row = 0; row < MAX_ROW; ++row) {
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
    std::normal_distribution<double> weight_int(WEIGHT_MEAN, WEIGHT_STD_DIV);
    return std::round(weight_int(gen));
}

void Eller::ExpandSetsVertical(int column) {
    existingSet.clear();
    int setStart = 0;
    int setEnd = 0;
    int currentSet = 0;
    while (true) {
        for (int row = setStart; row < MAX_ROW; ++row) {
            // If new set is detected,
            if (locationSet[row] != 0 && currentSet == 0){
                // set start point
                setStart = row;
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
                setEnd = row - 1;
                // But don't delete the set value.
                break;
            }
            if (row == MAX_ROW - 1){
                setEnd = row;
                break;
            }
        }

        std::random_device rd;
        std::mt19937 gen(rd());

        // Randomly generate the count of vertical expanding between 1 and the size of set.
        std::uniform_int_distribution<> expandCountGen(1, setEnd - setStart + 1);

        // Randomly generate the row value to expand vertically.
        std::uniform_int_distribution<> expandRowGen(setStart, setEnd);

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
        if (setEnd == MAX_ROW - 1) {
            for (int i = 0; i < MAX_ROW; i++){
                locationSet[i] = nextLocationSet[i];
                nextLocationSet[i] = 0;
            }
            break;
        } else {
            setStart = setEnd+1;
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
    if (row + 1 >= MAX_ROW){
        return;
    }
    // Groups two cells into the same set.
    if (locationSet[row] == 0 && locationSet[row + 1] != 0){
        locationSet[row] = locationSet[row + 1];
    } else{
        locationSet[row + 1] = locationSet[row];
    }

    // Open right side wall at the current cell.
    // This is accompanied by opening the left wall in the right cell.
    tempMaze->OpenWall(row, column, RIGHT, GenerateWeightND());
}

void Eller::MergeWithDown(int row, int column) {
    if (column + 1 >= MAX_COLUMN){
        return;
    }
    tempMaze->OpenWall(row, column, DOWN, GenerateWeightND());
}

void Eller::MergeWithDifferentSet(int column) {
    for (int row = 0; row < MAX_ROW - 1; ++row) {
        if (locationSet[row] != locationSet[row + 1]){
            MergeWithRight(row, column);
        }
    }
}

int Eller::getUnusedSetNumber() {
    // The number of sets is cannot over the maximum number of horizontal cells.
    for (int i = previouslyAssignedSetNumber + 1; i < MAX_ROW + 1; i++){
        // Find unused set number and assign it.
        if (existingSet.find(i) == existingSet.end()){
            previouslyAssignedSetNumber = i;
            return i;
        }
    }
    std::cout<<"Set number assigning error!"<<std::endl;
    exit(1);
}





