#pragma once
#include "TwoDimensionalShape.h"
#include <SFML/Graphics.hpp>

class Triangle : public TwoDimensionalShape {
    sf::ConvexShape tri;

public:
    Triangle(float size) {
        tri.setPointCount(3);
        tri.setPoint(0, sf::Vector2f(0.f, size));
        tri.setPoint(1, sf::Vector2f(size / 2.f, 0.f));
        tri.setPoint(2, sf::Vector2f(size, size));

        // Pink fill
        tri.setFillColor(sf::Color(255, 105, 180)); // Hot pink

        // White border
        tri.setOutlineColor(sf::Color::White);
        tri.setOutlineThickness(4.f);

        tri.setPosition(sf::Vector2f(100.f, 100.f));
    }

    void draw(sf::RenderWindow& window) override {
        window.draw(tri);
    }
};


