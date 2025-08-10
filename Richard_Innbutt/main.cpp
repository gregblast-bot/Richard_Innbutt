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

    // Ground
    platforms.emplace_back(0.f, static_cast<float>(windowYSize - 80),
        static_cast<float>(windowXSize), 80.f,
        sf::Color(128, 128, 128));

    int numOfPlatforms = 10;
    float blockWidth = windowXSize / (numOfPlatforms + (numOfPlatforms - 1) * 0.1f);
    float gap = blockWidth * 0.1f;

    for (int i = 0; i < numOfPlatforms; ++i) {
        float x = i * (blockWidth + gap);
        platforms.emplace_back(x, 0.f, blockWidth, blockWidth, sf::Color::Blue);
    }

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
