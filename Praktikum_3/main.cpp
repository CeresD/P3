#include <iostream>
#include <cstdlib>
#include <time.h>
#include "PriorityQueue.h"
#include "DiGraph.h"
#include "SFML/Graphics.hpp"
#include "SFMLGraphVisualizer.h"

const int MAX = 10;

int main() {

    /*PriorityQueue<std::string> *pq;
    pq = new PriorityQueue<std::string>();

    srand(unsigned(time(NULL)));

    for(int i = 0; i < MAX; i++) {

        pq->insert("sdfsf", ((float)rand()/(float)(RAND_MAX)) * 25);
    }

    pq->insert("asdasd", ((float)rand()/(float)(RAND_MAX)) * 25);

    pq->decreaseKey("asdasd", 7.0);


    for(int i = 0; i < MAX; i++) {

        std::cout << pq->extractMin() << std::endl;
    }

    pq->printQueue();

    delete pq;*/

    SFMLGraphVisualizer gv;
    DiGraph g(100);

    g.addNode(new Node("Aachen", 100, 600));
    g.addNode(new Node("Berlin", 300, 650));
    g.addNode(new Node("Koeln", 300, 300));
    g.addNode(new Node("Essen", 900, 300));
    g.addNode(new Node("Bonn", 300, 150));
    g.addNode(new Node("Krefeld", 100, 160));

    g.addEdge("Aachen", "Berlin", 7);
    g.addEdge("Koeln", "Aachen", 9);
    g.addEdge("Aachen", "Krefeld", 7);
    g.addEdge("Berlin", "Essen", 40);
    g.addEdge("Berlin", "Koeln", 3);
    g.addEdge("Koeln", "Essen", 31);
    g.addEdge("Bonn", "Essen", 8);
    g.addEdge("Krefeld", "Bonn", 1);

    Liste<Node *> n = g.getNodes();
    Liste<Edge *> e;

    for (int i = 0; i < n.size(); i++) {

        std::cout << "Node " << i << ": " << n.getValueAt(i)->getPositionX() << " " <<
                  n.getValueAt(i)->getPositionY() << " " << n.getValueAt(i)->getKey() <<
                  std::endl << " -> Edges:" << std::endl;

        e = g.getEdges(n.getValueAt(i)->getKey());

        for (int j = 0; j < e.size(); j++) {

            std::cout << "    " << e.getValueAt(j)->getStartNode()->getKey() << " " <<
                      e.getValueAt(j)->getEndNode()->getKey() << " " <<
                      e.getValueAt(j)->getWeight() << std::endl;

        }

        std::cout << std::endl;
    }

    gv.visualize(g);

    return 0;
}