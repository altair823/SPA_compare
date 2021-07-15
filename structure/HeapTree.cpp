//
// Created by 김태현 on 2021/07/11.
//

#include "HeapTree.h"

template<class T>
Node<T>::Node() {
    data = nullptr;
    parent = nullptr;
    lchild = nullptr;
    rchild = nullptr;
    preChildDir = 0;
}

template<class T>
Node<T>::Node(T *data) {
    this->data = data;
    parent = nullptr;
    lchild = nullptr;
    rchild = nullptr;
    preChildDir = 0;
}

template<class T>
void Node<T>::setData(const T *newData) {
    this->data = newData;
}

template<class T>
void Node<T>::setLChild(Node<T> newNode) {
    this->lchild = newNode;
    newNode.setParent(this);
}

template<class T>
void Node<T>::setRChild(Node<T> newNode) {
    this->rchild = newNode;
    newNode.setParent(this);
}

template<class T>
void Node<T>::setParent(Node<T> parentNode) {
    this->parent = parentNode;
}

template<class T>
T *Node<T>::getData() {
    return data;
}

template<class T>
Node<T> *Node<T>::getLChild() {
    return this->lchild;
}

template<class T>
Node<T> *Node<T>::getRChild() {
    return this->rchild;
}

template<class T>
void Node<T>::setPreChildDir(char dir) {
    this->preChildDir = dir;
}

template<class T>
char Node<T>::getPreChildDir() {
    return preChildDir;
}

template<class T>
Node<T> *Node<T>::getParent() {
    return this->parent;
}

template<class T>
HeapTree<T>::HeapTree() {
    head = nullptr;
}

template<class T>
void HeapTree<T>::setCompareFunc(const int *func) {
    this->CompareFunc = func;
}

template<class T>
void HeapTree<T>::EnqueueData(T *data) {
    Node<T> *newNode;
    newNode = new Node<T>(data);

    if (head == nullptr){
        head = newNode;
        return;
    }


    Node<T> *currentNode = head;

    if (CompareFunc(currentNode, newNode) == 1){
        if (currentNode == head){
            newNode->setLChild(currentNode->getLChild());
            newNode->setRChild(currentNode->getRChild());
            newNode->setParent(currentNode->getParent());
            if (currentNode == currentNode->getParent()->getLChild()){
                currentNode->getParent()->setLChild(newNode);
            } else{
                currentNode->getParent()->setRChild(newNode);
            }
            Node<T> *temp = currentNode;
            head = newNode;
            newNode = currentNode;
        }
    }

    if (currentNode->getPreChildDir() == RIGHT){

    }
}