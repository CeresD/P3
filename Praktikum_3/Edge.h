//
// Created by ceres on 02.05.18.
//

#ifndef PRAKTIKUM_3_EDGE_H
#define PRAKTIKUM_3_EDGE_H


#include "Node.h"
class Node;

class Edge {

    Node* startNode;
    Node* endNode;
    float weight;

public:

    Edge(Node* key1Node, Node* key2Node, float weight);
    ~Edge();

    float getWeight(void);
    Node* getStartNode(void);
    Node* getEndNode();

    void setWeight(float w);
    void setStartNode(Node* n);
    void setEndNode(Node* n);
};


#endif //PRAKTIKUM_3_EDGE_H
