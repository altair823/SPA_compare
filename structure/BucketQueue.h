//
// Created by 김태현 on 2021/07/27.
//

#ifndef SPA_COMPARE_BUCKETQUEUE_H
#define SPA_COMPARE_BUCKETQUEUE_H

#include <vector>
#include "../declaration.h"

template <class Key, class Value>
class BucketQueue{
private:
    /*
     * Theoretically, the maximum distance from the starting point to the location
     * is the Manhattan distance of the edge with maximum weight.
     */
    std::vector<Value*> bucketList[(MAX_ROW+MAX_COLUMN)*(WEIGHT_MEAN*2)];
    int bucketListSize = (MAX_ROW+MAX_COLUMN)*(WEIGHT_MEAN*2);

    // Store the index of bucket that has smallest key which is popped before.
    int minIndex = 0;
public:
    void Insert(Key key, Value &value);
    Value* PopMinimum();
    Key getMinimumKey();
};

template<class Key, class Value>
void BucketQueue<Key, Value>::Insert(Key key, Value &value) {
    int newIndex = key;
    if (newIndex < minIndex){
        minIndex = newIndex;
    }
    (bucketList[newIndex]).push_back(&value);
}

template<class Key, class Value>
Value* BucketQueue<Key, Value>::PopMinimum() {
    Value* v = bucketList[minIndex].back();
    bucketList[minIndex].pop_back();
    return v;
}


template<class Key, class Value>
Key BucketQueue<Key, Value>::getMinimumKey() {

    // The key of reducing time is saving the index which access before
    // and when access the list again, start linear search from the saved index.
    // But in A* algorithm, sum of weight and heuristic distance is may different before, and even smaller.
    // For that circumstances, subtract (mean of weight*2) from index which access before. 
    for (int i = minIndex; i < bucketListSize; ++i) {
        if (bucketList[i].size() > 0){
            minIndex = i;
            return i;
        }
    }
}



#endif //SPA_COMPARE_BUCKETQUEUE_H
