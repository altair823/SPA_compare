//
// Created by 김태현 on 2021/07/08.
//


#include "eller.h"

void Eller::printCurrentLocationSet() {
    for (int i : locationSet) {
        std::cout<<i<< " ";
    }
}

Eller::Eller(Maze &maze) {
    tempMaze = &maze;
}

void Eller::MakeMaze() {
    // Initial inserting. All cells in first raw are inserted in different sets.
    for (int i = 0; i < MAX_RAW; ++i) {
        locationSet[i] = i + 1;
    }

    // Merge cells in the first raw.
    for (int i = 0; i < MAX_RAW; ++i) {
        if (ChoiceRandomly()) {
            MergeWithRight(i, 0);
        }
    }
    printCurrentLocationSet();


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

void Eller::MergeWithRight(int raw, int column) {
    // If the right side cell doesn't exist, do nothing.
    if (raw + 1 >= MAX_RAW){
        return;
    }
    // Groups two cells into the same set.
    if (locationSet[raw] == 0 && locationSet[raw + 1] != 0){
        locationSet[raw] = locationSet[raw + 1];
    } else if (locationSet[raw] != 0 && locationSet[raw + 1] == 0){
        locationSet[raw + 1] = locationSet[raw];
    } else{
        locationSet[raw + 1] = locationSet[raw];
    }

    // Open right side wall at the current cell.
    // This is accompanied by opening the left wall in the right cell.
    tempMaze->OpenWall(raw, column, RIGHT);
}

void Eller::MergeWithDown(int raw, int column) {
    if (column + 1 >= MAX_COLUMN){
        return;
    }

}


