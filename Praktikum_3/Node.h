//
// Created by ceres on 02.05.18.
//

#ifndef PRAKTIKUM_3_NODE_H
#define PRAKTIKUM_3_NODE_H


#include <string>
#include "Edge.h"
#include "liste.h"
class Edge;

class Node {

    std::string node_key;
    int position_x, position_y;
    Liste<Edge*> edges;

public:

    Node(std::string key, int posX, int posY);
    ~Node();

    std::string getKey(void);
    int getPositionX(void);
    int getPositionY(void);
    Liste<Edge*> getEdges(void);

    void setKey(std::string new_key);
    void setPositionX(int x);
    void setPositionY(int y);
    void setNewEdge(Edge* edge);
};


#endif //PRAKTIKUM_3_NODE_H
