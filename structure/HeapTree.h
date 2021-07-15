//
// Created by 김태현 on 2021/07/11.
//

#ifndef SPA_COMPARE_HEAPTREE_H
#define SPA_COMPARE_HEAPTREE_H

#define LEFT -1
#define RIGHT 1

#include <vector>
#include "../map/Location.h"

template <class T>
class Node{
private:
    T *data;
    Node *parent;
    Node *lchild;
    Node *rchild;
    char preChildDir;
public:
    Node();
    explicit Node(T *data);
    void setData(const T *newData);
    T *getData();
    void setLChild(Node<T> newNode);
    void setRChild(Node<T> newNode);
    void setParent(Node<T> parentNode);
    Node<T> *getLChild();
    Node<T> *getRChild();
    Node<T> *getParent();
    void setPreChildDir(char dir);
    char getPreChildDir();
};

template <class T>
class HeapTree{
private:
    Node<T> head;
    int (*CompareFunc)(Node<T>, Node<T>);
public:
    HeapTree();
    void setCompareFunc(const int *func);
    void EnqueueData(T *data);
    Node<T> DequeueNode();
    T *DequeueData();
};


#endif //SPA_COMPARE_HEAPTREE_H
