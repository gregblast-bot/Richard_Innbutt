#ifndef PLATFORM_H
#define PLATFORM_H

#include <SFML/Graphics.hpp> // For sf::RectangleShape, sf::Vector2f, sf::Color

// Define a simple Platform class to hold platform properties
class Platform {
public:
    sf::RectangleShape shape;

    // Constructor declaration
    Platform(float x, float y, float width, float height, sf::Color color = sf::Color(128, 128, 128));
};

#endif // PLATFORM_H