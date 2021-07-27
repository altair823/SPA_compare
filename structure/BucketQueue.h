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
    std::vector<std::vector<Value*>> bucketList;
    int bucketListSize = (MAX_ROW+MAX_COLUMN)*20;
    int (*MakeKeyToIndex)(Key&);
    int beforeSearchIndex = 0;
public:
    void setKeyMaker(int (*MKTI)(Key&));
    void Insert(Key key, Value &value);
    Value* PopMinimum();
    Key getMinimumKey();
};

template<class Key, class Value>
void BucketQueue<Key, Value>::setKeyMaker(int (*MKTI)(Key&)) {
    MakeKeyToIndex = MKTI;
}

template<class Key, class Value>
void BucketQueue<Key, Value>::Insert(Key key, Value &value) {
    int newIndex = key;

    if (newIndex >= bucketList.size()){
        bucketList.resize(newIndex * 2 + 1);
    }

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
    for (int i = beforeSearchIndex; i < bucketList.size(); ++i) {
        if (bucketList[i].size() > 0){
            beforeSearchIndex = i;
            return i;
        }
    }
}



#endif //SPA_COMPARE_BUCKETQUEUE_H
