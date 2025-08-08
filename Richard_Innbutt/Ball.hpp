#ifndef Ball_H
#define Ball_H

#include <SFML/Graphics.hpp>
#include <vector> // For std::vector<Platform> in update

// Forward declaration of Platform to avoid circular dependency
// This is crucial because Ball's update method takes a const std::vector<Platform>&
class Platform;

// A new Ball class to handle projectiles
class Ball {
private:
    sf::Sprite m_sprite;
    // Note: Textures are passed by reference and stored directly, so they don't need to be
    // member variables here if they are managed externally.
    // However, if they are meant to be owned by the Ball, they would be declared here
    // and loaded in the constructor, similar to your Character class.
    // Given your constructor, it seems like they are passed by reference,
    // so the members m_BallTexture and m_explosionTexture would be references or pointers.
    // For simplicity and to match your original code's member texture usage,
    // I'll keep them as sf::Texture objects and assume they are loaded externally and assigned.
    // If you intend for the Ball to *own* its textures (load them itself),
    // then the constructor should take string paths instead of sf::Texture&.
    // For now, I'm sticking to the structure provided.
    sf::Texture m_BallTexture;
    sf::Texture m_explosionTexture;


    sf::Vector2f m_velocity;
    float m_gravity = 0.5f;

    bool m_isExploding = false;
    bool m_isFinished = false;

    int m_animationTimer = 0;
    int m_explosionFrame = 0;

public:
    // Constructor for the Ball
    Ball(sf::Vector2f startPos, float launchVelocity, float directionX, sf::Texture& BallTexture, sf::Texture& explosionTexture);

    void update(const std::vector<Platform>& platforms);
    void draw(sf::RenderWindow& window);

    sf::FloatRect getBounds() const;
    bool isExploding() const;
    bool isFinished() const;

    // Trigger the explosion
    void explode();

    // Get position to check for damage to enemies in a radius.
    sf::Vector2f getPosition() const;

    // Damage area for explosion
    sf::FloatRect getExplosionBounds() const;
};

#endif // Ball_H#pragma once
