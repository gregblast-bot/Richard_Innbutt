#include "Ball.hpp"
#include "Platform.hpp"
#include "Game.hpp"
#include "GameStates.h"
#include <iostream>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <algorithm>
#include <cmath>

std::vector<Platform> createPlatforms(int windowXSize, int windowYSize, int level) {
    std::vector<Platform> platforms;

    // Border sizes
    float verticalBorderWidth = windowYSize * 0.0740740741f;
    float horizontalBorderHeight = windowXSize * 0.0416666667f;

    // Ground
    platforms.emplace_back(0.f, windowYSize - verticalBorderWidth,
        windowXSize, verticalBorderWidth, sf::Color(128, 128, 128));

    // Top border
    platforms.emplace_back(0.f, 0.f,
        windowXSize, verticalBorderWidth, sf::Color(128, 128, 128));

    // Left border
    platforms.emplace_back(0.f, 0.f,
        horizontalBorderHeight, windowYSize, sf::Color(128, 128, 128));

    // Right border
    platforms.emplace_back(windowXSize - horizontalBorderHeight, 0.f,
        horizontalBorderHeight, windowYSize, sf::Color(128, 128, 128));

    // Platform settings
    int rows = 3;
    int numPlatforms = 20 * level; // same for each row
	float blockGapPercentage = 0.05f; // 25% gap between blocks
    float availableWidth = windowXSize - 2 * verticalBorderWidth;
    float availableHeight = windowYSize - 2 * horizontalBorderHeight;

    float blockWidth = availableWidth / (numPlatforms + (numPlatforms - 1.0) * blockGapPercentage); // 25% gap
    float gapX = blockWidth * blockGapPercentage;
    float blockHeight = blockWidth; // square blocks

    // Vertical spacing between rows inside borders
    float verticalGap = (availableHeight - rows * blockHeight) / (rows + 1);
    float gapY = blockHeight * blockGapPercentage;

    for (int row = 0; row < rows; ++row) {
        float y = horizontalBorderHeight + (blockHeight + gapY) * row;

        for (int i = 0; i < numPlatforms; ++i) {
            float x = horizontalBorderHeight + i * (blockWidth + gapX);
            platforms.emplace_back(x, y, blockWidth, blockHeight, sf::Color::Blue);
        }
    }

	float xSizeOfPlayerPlatform = 50.f; // Width of the platform for the player
    float ySizeOfPlayerPlatform = 10.f; // Height of the platform for the player
    // Calculate the position for the player platform
    float x = (windowXSize - xSizeOfPlayerPlatform) / 2.f; // Centered horizontally
    float y = windowYSize - horizontalBorderHeight - ySizeOfPlayerPlatform; // Centered vertically
    // Create a platform for the player
	platforms.emplace_back(x, y, xSizeOfPlayerPlatform, ySizeOfPlayerPlatform, sf::Color::Red);


    return platforms;
}


int main()
{
    // Use getDesktopMode to automatically get the monitor's resolution
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    // Create a full-screen window initially.
    sf::RenderWindow window(desktopMode, "Game", sf::Style::Fullscreen);
    window.setFramerateLimit(60);

    // Keep track of the window state
    bool isFullScreen = true;

    // Default window dimensions for non-fullscreen mode
    const int defaultWindowWidth = 1280;
    const int defaultWindowHeight = 720;

    // Get the window size for positioning other elements
    float windowXSize = static_cast<float>(window.getSize().x);
    float windowYSize = static_cast<float>(window.getSize().y);

    // Platforms and Ground
    // Create a vector to hold all platforms, including the main ground
    std::vector<Platform> platforms = createPlatforms(windowXSize, windowYSize, 1);

    // Create game state machine
    Game game;

    // Create Pause Menu
    //PauseMenu pauseMenu(800, 600);


    //// Use a vector of unique pointers to store multiple enemies
    //std::vector<std::unique_ptr<Enemy>> enemies;
    //int currentWave = 1;

    //// Spawn the first wave
    //spawnWave(enemies, windowYSize, currentWave);
    //for (auto& enemy : enemies) {
    //    enemy->snapToPlatform(platforms[0]);
    //}

    //// New vector to hold Balls
    //std::vector<std::unique_ptr<Ball>> Balls;

    game.setState(Running);



    while (window.isOpen())
    {

        sf::Event event;

        // Get inputs
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    
        // Clear window data
        window.clear();

        // Game State
        switch (game.getState()) {
        case Running: {

            // Draw all platforms
            for (const auto& platform : platforms) {
                window.draw(platform.shape);
            }

            if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 30) {
				platforms[platforms.size() - 1].shape.move(5, 0);
            }
            else if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -30) {
                platforms[platforms.size() - 1].shape.move(-5, 0);
            }
            else {
                
            }
            break;
        }

        case Paused:

            break;
        default:
            break;
        }

        // Update window
        window.display();
    }

    

    return 0;
}
