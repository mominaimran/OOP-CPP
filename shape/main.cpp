#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({400, 400}), "SFML works!"); // bigger window for triangle

    // Create a triangle
    sf::ConvexShape shape;
    shape.setPointCount(3);                  // 3 points = triangle
    shape.setPoint(0, sf::Vector2f(200.f, 50.f));   // top
    shape.setPoint(1, sf::Vector2f(100.f, 350.f));  // bottom left
    shape.setPoint(2, sf::Vector2f(300.f, 350.f));  // bottom right
    shape.setFillColor(sf::Color::Yellow);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}
