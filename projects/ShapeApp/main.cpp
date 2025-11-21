#include <SFML/Graphics.hpp>
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "Sphere.h"
#include "Cube.h"
#include "Tetrahedron.h"
#include <iostream>
#include <optional>
int main() {
    sf::RenderWindow window(sf::VideoMode({600u, 600u}), "Shape Drawer");
    Shape* shape = nullptr;
    while (window.isOpen()) {
        // --- Event Handling ---
        while (auto eventOpt = window.pollEvent()) {
            auto& event = *eventOpt;
            if (event.is<sf::Event::Closed>()) {
                window.close();
            }
        }
        // --- Input Handling ---
        std::cout << "\n---- Choose type of shape ---- \n1. 2D\n2. 3D\n0. Exit\n";
        int dimChoice;
        std::cout << "Choose dimension: ";
        std::cin >> dimChoice;
        if (dimChoice == 0) break;
        delete shape;
        shape = nullptr;
        if (dimChoice == 1) {
            std::cout << "\n **** Choose 2D shape ****\n1. Circle\n2. Square\n3. Triangle\n";
            int choice2D;
            std::cout << "Choice: ";
            std::cin >> choice2D;
            switch(choice2D) {
                case 1: shape = new Circle(100.f); break;
                case 2: shape = new Square(150.f); break;
                case 3: shape = new Triangle(150.f); break;
                default: std::cout << "Invalid 2D choice!\n"; continue;
            }
        } else if (dimChoice == 2) {
            std::cout << "\n **** Choose 3D shape ****\n1. Sphere\n2. Cube\n3. Tetrahedron\n";
            int choice3D;
            std::cout << "Choice: ";
            std::cin >> choice3D;
            switch(choice3D) {
                case 1: shape = new Sphere(80.f); break;
                case 2: shape = new Cube(120.f); break;
                case 3: shape = new Tetrahedron(120.f); break;
                default: std::cout << "Invalid 3D choice!\n"; continue;
            }
        } else {
            std::cout << "Invalid choice!\n";
            continue;
        }
        // --- Draw Loop (one frame after input) ---
        window.clear(sf::Color::Black);
        if (shape) shape->draw(window);
        window.display();
    }
    delete shape;
    return 0;
}
