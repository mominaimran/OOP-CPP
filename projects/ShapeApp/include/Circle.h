#pragma once
#include "TwoDimensionalShape.h"
#include <SFML/Graphics.hpp>

class Circle : public TwoDimensionalShape {
    sf::CircleShape circle;
    sf::CircleShape glow;
public:
    Circle(float radius) {

        // Glow circle (bigger + soft)
        glow.setRadius(radius + 6.f);         
        glow.setFillColor(sf::Color(255, 255, 255, 70));  // white & transparent
        glow.setOutlineThickness(8.f);
        glow.setOutlineColor(sf::Color(255, 255, 255, 90));  
        glow.setPosition(sf::Vector2f(100.f - 6.f, 100.f - 6.f));

        // Main circle
        circle.setRadius(radius);
        circle.setFillColor(sf::Color::Magenta);
        circle.setOutlineThickness(3.f);
        circle.setOutlineColor(sf::Color::White);
        circle.setPosition(sf::Vector2f(100.f, 100.f));
    }

    void draw(sf::RenderWindow& window) override {
        window.draw(glow);      // draw glow first
        window.draw(circle);    // then draw main circle
    }
};
