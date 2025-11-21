#pragma once
#include "ThreeDimensionalShape.h"
#include <SFML/Graphics.hpp>
class Cube : public ThreeDimensionalShape {
    sf::ConvexShape front;
    sf::ConvexShape right;
    sf::ConvexShape top;
public:
    Cube(float size = 120.f) {   // smaller default size
        // Smaller offset so cube looks correct
        float offset = size * 0.4f;
        // ------------ FRONT FACE ------------
        front.setPointCount(4);
        front.setPoint(0, {0, 0});
        front.setPoint(1, {size, 0});
        front.setPoint(2, {size, size});
        front.setPoint(3, {0, size});
        front.setFillColor({70, 110, 255});
        front.setPosition({150.f, 150.f});   // moved upward
        // ------------ RIGHT FACE ------------
        right.setPointCount(4);
        right.setPoint(0, {size, 0});
        right.setPoint(1, {size + offset, -offset});
        right.setPoint(2, {size + offset, size - offset});
        right.setPoint(3, {size, size});
        right.setFillColor({40, 70, 200});
        right.setPosition({150.f, 150.f});
        // ------------ TOP FACE ------------
        top.setPointCount(4);
        top.setPoint(0, {0, 0});
        top.setPoint(1, {offset, -offset});
        top.setPoint(2, {size + offset, -offset});
        top.setPoint(3, {size, 0});
        top.setFillColor({110, 150, 255});
        top.setPosition({150.f, 150.f});
    }
    void draw(sf::RenderWindow& window) override {
        window.draw(top);
        window.draw(right);
        window.draw(front);
    }
};
