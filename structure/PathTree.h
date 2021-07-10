//
// Created by 김태현 on 2021/07/11.
//

#ifndef SPA_COMPARE_PATHTREE_H
#define SPA_COMPARE_PATHTREE_H

#include <vector>
#include "map/Location.h"

class Node{
private:
    Location *location;
    int distance;
    Node *parent;
    std::vector<Node *> child;
public:
    Node();
    Node(Location *newocation);
    void setLocation(Location *newLocation);
    void setDistance(int dist);
    void setChild(Node *childNode);
    void setParent(Node *parentNode);
    Node *getParent();
};

class PathTree{
private:
    Node *root;
public:
    PathTree();
    void InsertLocation(Node *previousNode, Location *newLocation, int dist);
};

#endif //SPA_COMPARE_PATHTREE_H
