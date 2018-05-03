//
// Created by ceres on 02.05.18.
//

#include "Edge.h"
#include "Node.h"

Edge::Edge(Node* key1Node, Node* key2Node, float weight) {

    setStartNode(key1Node);
    setEndNode(key2Node);
    setWeight(weight);
}

Edge::~Edge() {

    delete this;
}

float Edge::getWeight() {

    return weight;
}

Node* Edge::getStartNode() {

    return startNode;
}

Node* Edge::getEndNode() {

    return endNode;
}

void Edge::setWeight(float w) {

    weight = w;
}

void Edge::setStartNode(Node *n) {

    startNode = n;
}

void Edge::setEndNode(Node *n) {

    endNode = n;
}
