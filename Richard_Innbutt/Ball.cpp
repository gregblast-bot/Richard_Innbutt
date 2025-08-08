#include "Ball.hpp"
#include "Platform.hpp"

// Constructor for the Ball
Ball::Ball(sf::Vector2f startPos, float launchVelocity, float directionX, sf::Texture& BallTexture, sf::Texture& explosionTexture)
    : m_BallTexture(BallTexture), m_explosionTexture(explosionTexture) {
    m_sprite.setTexture(m_BallTexture);
    m_sprite.setPosition(startPos);
    m_sprite.setOrigin(m_BallTexture.getSize().x / 2, m_BallTexture.getSize().y / 2);
    m_velocity.x = 8.0f * directionX; // Launch direction
    m_velocity.y = -launchVelocity; // Initial upward velocity
}

void Ball::update(const std::vector<Platform>& platforms) {
    if (m_isExploding) {
        // Explosion animation logic
        m_animationTimer++;
        if (m_animationTimer >= 4) { // Adjust animation speed
            m_animationTimer = 0;
            m_explosionFrame++;
            if (m_explosionFrame < 4) { // Number of frames in explosion animation
                m_sprite.setTextureRect(sf::IntRect(m_explosionFrame * 64, 0, 64, 64));
            }
            else {
                m_isFinished = true; // Ball is finished exploding
            }
        }
    }
    else {
        // Projectile physics
        m_velocity.y += m_gravity;
        m_sprite.move(m_velocity);

        // Check for collision with platforms
        for (const auto& platform : platforms) {
            if (m_sprite.getGlobalBounds().intersects(platform.shape.getGlobalBounds())) {
                explode(); // Explode on impact
                break;
            }
        }
    }
}

void Ball::draw(sf::RenderWindow& window) {
    window.draw(m_sprite);
}

sf::FloatRect Ball::getBounds() const {
    return m_sprite.getGlobalBounds();
}

bool Ball::isExploding() const {
    return m_isExploding;
}

bool Ball::isFinished() const {
    return m_isFinished;
}

// Trigger the explosion
void Ball::explode() {
    if (!m_isExploding) {
        m_isExploding = true;
        m_sprite.setTexture(m_explosionTexture);
        m_sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
        m_sprite.setOrigin(32, 32); // Center the explosion texture
    }
}

// Get position to check for damage to enemies in a radius.
sf::Vector2f Ball::getPosition() const {
    return m_sprite.getPosition();
}

// Damage area for explosion
sf::FloatRect Ball::getExplosionBounds() const {
    // Adjust the size and position of the explosion bounds
    float explosionRadius = 80.f; // The radius of the explosion
    return sf::FloatRect(m_sprite.getPosition().x - explosionRadius, m_sprite.getPosition().y - explosionRadius, explosionRadius * 2, explosionRadius * 2);
}