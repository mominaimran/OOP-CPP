#pragma once
#include "ThreeDimensionalShape.h"
#include <SFML/Graphics.hpp>
class Sphere : public ThreeDimensionalShape {
    sf::CircleShape baseSphere;
    sf::CircleShape highlight;
public:
    Sphere(float radius = 80.f) {
        // --- Base Sphere ---
        baseSphere.setRadius(radius);
        baseSphere.setPointCount(100);
        baseSphere.setFillColor(sf::Color(40, 180, 40));  // Dark green
        baseSphere.setOrigin({radius, radius});
        baseSphere.setPosition({300.f, 200.f});           // Center in window
        // --- Highlight (single light) ---
        float highlightRadius = radius * 0.6f;            // 60% of base
        highlight.setRadius(highlightRadius);
        highlight.setPointCount(100);
        highlight.setFillColor(sf::Color(140, 255, 140, 200)); // Lighter green, semi-transparent
        highlight.setOrigin({highlightRadius, highlightRadius});
        highlight.setPosition({
            300.f - radius * 0.2f,   // Slight top-left offset
            200.f - radius * 0.2f
        });
    }
    void draw(sf::RenderWindow& window) override {
        window.draw(baseSphere);
        window.draw(highlight);
    }
};
