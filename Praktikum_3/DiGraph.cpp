//
// Created by ceres on 02.05.18.
//

#include "DiGraph.h"
#include "Node.h"
#include "Edge.h"

DiGraph::DiGraph(int arr_size) {
    nodes = new Node*[arr_size];
    size = 0;
}

DiGraph::~DiGraph() {
    delete[] nodes;
}

void DiGraph::addNode(Node *node) {

    nodes[size] = node;
    size++;
}

void DiGraph::addEdge(std::string key1, std::string key2, float weight) {

    Node* key1Node = NULL;
    Node* key2Node = NULL;
    int adjaIndex = 0;

    for(int i = 0; i < size; i++) {
        if(nodes[i]->getKey() == key1) {
            key1Node = nodes[i];
            adjaIndex = i;
        }

        if(nodes[i]->getKey() == key2) {
            key2Node = nodes[i];
        }
    }

    if(key1Node != NULL && key2Node != NULL) {

        Edge* e = new Edge(key1Node, key2Node, weight);
        nodes[adjaIndex]->setNewEdge(e);
    }
}

Liste<Node*> DiGraph::getNeighbours(std::string key) {

}

Liste<Edge*> DiGraph::getEdges(std::string key) {

    Liste<Edge*> list;

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < nodes[i]->getEdges().size(); j++) {

            if(nodes[i]->getEdges().getValueAt(j)->getStartNode()->getKey() == key) {
                list.append(nodes[i]->getEdges().getValueAt(j));
            }
        }
    }

    return list;
}

Liste<Node*> DiGraph::getNodes() {

    Liste<Node*> *l = new Liste<Node*>();

    for(int i = 0; i < size; i++) {
        l->append(nodes[i]);
    }

    return *l;
}

