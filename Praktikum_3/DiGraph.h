//
// Created by ceres on 02.05.18.
//

#ifndef PRAKTIKUM_3_DIGRAPH_H
#define PRAKTIKUM_3_DIGRAPH_H


#include <string>
#include "Node.h"
#include "liste.h"
#include "Edge.h"

class DiGraph {

    Node** nodes;
    int size;

public:

    DiGraph(int arr_size);
    ~DiGraph();

    void addNode(Node* node);
    void addEdge(std::string key1, std::string key2, float weight);
    Liste<Node*> getNeighbours(std::string key);
    Liste<Edge*> getEdges(std::string key);
    Liste<Node*> getNodes();
};


#endif //PRAKTIKUM_3_DIGRAPH_H
