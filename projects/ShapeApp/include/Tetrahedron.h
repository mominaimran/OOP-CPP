#pragma once
#include "ThreeDimensionalShape.h"
#include <SFML/Graphics.hpp>

class Tetrahedron : public ThreeDimensionalShape {
    sf::ConvexShape frontFace;
    sf::ConvexShape rightFace;
    sf::ConvexShape leftFace;

    sf::VertexArray edges; // wireframe

public:
    Tetrahedron(float size = 120.f)
        : edges(sf::PrimitiveType::Lines)  // SFML 3 FIX
    {
        float offset = size * 0.35f; 
        sf::Vector2f pos = {200.f, 150.f};

        // ---------------- FRONT FACE ----------------
        frontFace.setPointCount(3);
        frontFace.setPoint(0, {size / 2.f, 0.f});
        frontFace.setPoint(1, {0.f, size});
        frontFace.setPoint(2, {size, size});
        frontFace.setFillColor({255, 90, 90});
        frontFace.setPosition(pos);

        // ---------------- RIGHT FACE ----------------
        rightFace.setPointCount(3);
        rightFace.setPoint(0, {size / 2.f, 0.f});
        rightFace.setPoint(1, {size, size});
        rightFace.setPoint(2, {size / 2.f + offset, size + offset});
        rightFace.setFillColor({200, 60, 60});
        rightFace.setPosition(pos);

        // ---------------- LEFT FACE -----------------
        leftFace.setPointCount(3);
        leftFace.setPoint(0, {size / 2.f, 0.f});
        leftFace.setPoint(1, {0.f, size});
        leftFace.setPoint(2, {size / 2.f - offset, size + offset});
        leftFace.setFillColor({150, 40, 40});
        leftFace.setPosition(pos);

        // =========================================================
        // LINE DRAWING HELPER
        // =========================================================
        auto addLine = [&](sf::Vector2f a, sf::Vector2f b) {
            sf::Vertex v1, v2;
            v1.position = a + pos;
            v2.position = b + pos;
            v1.color = sf::Color::White;
            v2.color = sf::Color::White;
            edges.append(v1);
            edges.append(v2);
        };

        // Shared vertices
        sf::Vector2f top(size / 2.f, 0.f);
        sf::Vector2f bottomLeft(0.f, size);
        sf::Vector2f bottomRight(size, size);
        sf::Vector2f farLeft(size / 2.f - offset, size + offset);
        sf::Vector2f farRight(size / 2.f + offset, size + offset);

        // -------- FRONT
        addLine(top, bottomLeft);
        addLine(bottomLeft, bottomRight);
        addLine(bottomRight, top);

        // -------- RIGHT
        addLine(top, bottomRight);
        addLine(bottomRight, farRight);
        addLine(farRight, top);

        // -------- LEFT
        addLine(top, bottomLeft);
        addLine(bottomLeft, farLeft);
        addLine(farLeft, top);
    }

    void draw(sf::RenderWindow& window) override {
        window.draw(leftFace);
        window.draw(rightFace);
        window.draw(frontFace);
        window.draw(edges);
    }
};

