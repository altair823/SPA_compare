//
// Created by 김태현 on 2021/07/11.
//

#include "PathTree.h"

Node::Node() {
    location = nullptr;
    distance = 0;
    parent = nullptr;
}

Node::Node(Location *newLocation) {
    location = newLocation;
    distance = 0;
    parent = nullptr;
}

void Node::setLocation(Location *newLocation) {
    location = newLocation;
}

void Node::setChild(Node *childNode) {
    child.push_back(childNode);
}

Node *Node::getParent() {
    return parent;
}

void Node::setDistance(int dist) {
    distance = dist;
}

void Node::setParent(Node *parentNode) {
    parent = parentNode;
}

PathTree::PathTree() {
    root = nullptr;
}

void PathTree::InsertLocation(Node *previousNode, Location *newLocation, int dist) {
    if (root == nullptr){
        root = new Node(newLocation);
        root->setDistance(dist);
    } else{
        Node *newNode = new Node(newLocation);
        newNode->setDistance(dist);
        newNode->setParent(previousNode);
        previousNode->setChild(newNode);
    }
}

