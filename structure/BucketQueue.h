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
    int beforeSearchIndex{};
public:
    void Insert(Key key, Value &value);
    Value* PopMinimum();
    Key getMinimumKey();
};

template<class Key, class Value>
void BucketQueue<Key, Value>::Insert(Key key, Value &value) {
    int newIndex = key;
    (bucketList[newIndex]).push_back(&value);
}

template<class Key, class Value>
Value* BucketQueue<Key, Value>::PopMinimum() {
    Value* v = bucketList[beforeSearchIndex].back();
    bucketList[beforeSearchIndex].pop_back();
    return v;
}


template<class Key, class Value>
Key BucketQueue<Key, Value>::getMinimumKey() {

    // The key of reducing time is saving the index which access before
    // and when access the list again, start linear search from the saved index.
    for (int i = beforeSearchIndex-(WEIGHT_MEAN*2); i < bucketListSize; ++i) {
        if (i<0){
            i = 0;
        }
        if (bucketList[i].size() > 0){
            beforeSearchIndex = i;
            return i;
        }
    }
}



#endif //SPA_COMPARE_BUCKETQUEUE_H
