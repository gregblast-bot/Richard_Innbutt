#include "Platform.hpp" // Include its own header

// Constructor implementation
Platform::Platform(float x, float y, float width, float height, sf::Color color) {
    shape.setSize(sf::Vector2f(width, height));
    shape.setPosition(x, y);
    shape.setFillColor(color);
}