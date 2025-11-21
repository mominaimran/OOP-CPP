#pragma once
#include "TwoDimensionalShape.h"
#include <SFML/Graphics.hpp>

class Square : public TwoDimensionalShape {
    sf::RectangleShape rect;
public:
    Square(float size) {
        rect.setSize(sf::Vector2f(size, size));
        rect.setFillColor(sf::Color::Cyan);
        rect.setPosition(sf::Vector2f(100.f, 100.f));

        // --- BLUE OUTLINE BORDER ---
        rect.setOutlineThickness(3.f);            // border width
        rect.setOutlineColor(sf::Color(0, 120, 255)); // nice blue
    }

    void draw(sf::RenderWindow& window) override {
        window.draw(rect);
    }
};


