//
// Created by ceres on 02.05.18.
//

#include "Node.h"
#include "Edge.h"

Node::Node(std::string key, int posX, int posY) {

    setPositionX(posX);
    setPositionY(posY);
    setKey(key);
}

Node::~Node() {

    delete this;
}

std::string Node::getKey() {

    return node_key;
}

int Node::getPositionX() {

    return position_x;
}

int Node::getPositionY() {

    return position_y;
}

Liste<Edge *> Node::getEdges() {

    return edges;
}

void Node::setKey(std::string new_key) {

    node_key = new_key;
}

void Node::setPositionX(int x) {

    position_x = x;
}

void Node::setPositionY(int y) {

    position_y = y;
}

void Node::setNewEdge(Edge *edge) {

    edges.append(edge);
}