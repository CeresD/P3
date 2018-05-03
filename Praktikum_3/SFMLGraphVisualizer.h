//
// Created by ceres on 02.05.18.
//

#ifndef PRAKTIKUM_3_SFMLGRAPHVISUALIZER_H
#define PRAKTIKUM_3_SFMLGRAPHVISUALIZER_H


#include "DiGraph.h"
#include "SFML/Graphics.hpp"

#define NODERADIUS 30

class SFMLGraphVisualizer {

    sf::RenderWindow window;
    sf::Font font;

public:

    SFMLGraphVisualizer();
    void visualize(DiGraph &g);
    void drawNode(Node &node, sf::Color nodeColor);
    void drawEdge(Edge &edge, sf::Color color, double weight, int thickness = 1, int arrowMagnitude = 20);

};


#endif //PRAKTIKUM_3_SFMLGRAPHVISUALIZER_H
