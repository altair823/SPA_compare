//
// Created by 김태현 on 2021/07/08.
//


#include "eller.h"

void Eller::MakeMaze(Maze &maze) {
    // Initial inserting. All cells in first raw are inserted in different sets.
    for (int i = 0; i < MAX_RAW; ++i) {
        locationSet[0][i] = i;
    }

    for (int i = 0; i < MAX_RAW; ++i) {
        if (ChoiceRandomly()) {
            maze[0][i]
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

void Eller::MergeWithRight(int x) {
    locationSet[x]
}

