//
// Created by ceres on 02.05.18.
//

#include <cmath>
#include <sstream>
#include "SFMLGraphVisualizer.h"

SFMLGraphVisualizer::SFMLGraphVisualizer() {

    this->font.loadFromFile("../Font/OpenSans-Regular.ttf");
}

void SFMLGraphVisualizer::visualize(DiGraph &g) {

    window.create(sf::VideoMode(1024, 768), "Visualized Graph");

    Liste<Node *> nodes = g.getNodes();

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        for (int i = 0; i < nodes.size(); i++) {
            Node *node = nodes.getValueAt(i);

            sf::Color color(255, 0, 0);
            drawNode(*node, color);

            Liste<Edge *> edges = g.getEdges(node->getKey());

            for (int j = 0; j < edges.size(); j++) {
                drawEdge(*(edges.getValueAt(j)), sf::Color::Black, edges.getValueAt(j)->getWeight(), 1);
            }
        }

        window.display();
    }
}

void SFMLGraphVisualizer::drawNode(Node &node, sf::Color nodeColor) {

    sf::CircleShape Circle(NODERADIUS);
    Circle.setPosition(node.getPositionX() - NODERADIUS, node.getPositionY() - NODERADIUS);
    Circle.setFillColor(sf::Color::White);
    Circle.setOutlineColor(nodeColor);
    Circle.setOutlineThickness(5);

    window.draw(Circle);

    sf::Text Label(node.getKey(), font, 32);
    Label.setPosition(node.getPositionX() - NODERADIUS / 2 + 5, node.getPositionY() - NODERADIUS / 2 - 5);
    Label.setFillColor(sf::Color::Blue);

    window.draw(Label);
}

void SFMLGraphVisualizer::drawEdge(Edge &edge, sf::Color color, double weight, int thickness, int arrowMagnitude) {

    sf::Vector2f p(edge.getStartNode()->getPositionX(), edge.getStartNode()->getPositionY());
    sf::Vector2f q(edge.getEndNode()->getPositionX(), edge.getEndNode()->getPositionY());

    const double PI = 3.141592653;
    double angle = atan2((double) p.y - q.y, (double) p.x - q.x);

    q.x = (int) (q.x + NODERADIUS * cos(angle));
    q.y = (int) (q.y + NODERADIUS * sin(angle));
    p.x = (int) (p.x - NODERADIUS * cos(angle));
    p.y = (int) (p.y - NODERADIUS * sin(angle));

    sf::Vertex line[2] = {
            sf::Vertex(sf::Vector2f(p.x, p.y), color),
            sf::Vertex(sf::Vector2f(q.x, q.y), color)
    };

    window.draw(line, 2, sf::Lines);

    std::stringstream weightstring;
    weightstring << weight;

    sf::Text Labelweight(weightstring.str(), font, 32);
    int size = sqrt(pow(p.x - q.x, 2) + pow(p.y - q.y, 2));
    Labelweight.setPosition(p.x - (size / 2) * cos(angle) + 10 * sin(angle),
                            p.y - (size / 2) * sin(angle) + 10 * cos(angle));
    Labelweight.setFillColor(sf::Color::Blue);
    window.draw(Labelweight);

    p.x = (int) (q.x + arrowMagnitude * cos(angle + PI / 8));
    p.y = (int) (q.y + arrowMagnitude * sin(angle + PI / 8));
    sf::Vertex first[2] = {
                    sf::Vertex(sf::Vector2f(p.x, p.y), color),
                    sf::Vertex(sf::Vector2f(q.x, q.y), color)
            };
    window.draw(first, 2, sf::Lines);

    p.x = (int) (q.x + arrowMagnitude * cos(angle - PI / 8));
    p.y = (int) (q.y + arrowMagnitude * sin(angle - PI / 8));
    sf::Vertex second[2] = {
                    sf::Vertex(sf::Vector2f(p.x, p.y), color),
                    sf::Vertex(sf::Vector2f(q.x, q.y), color)
            };
    window.draw(second, 2, sf::Lines);

}