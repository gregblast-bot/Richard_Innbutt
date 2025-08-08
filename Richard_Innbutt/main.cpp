#include "Ball.hpp"
#include "Platform.hpp"
#include "Game.hpp"
#include <iostream>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <algorithm>
#include <cmath>

// Create platforms based on window size
std::vector<Platform> createPlatforms(int windowXSize, int windowYSize) {
    std::vector<Platform> platforms;
    // Main ground platform
    platforms.emplace_back(0.f, static_cast<float>(windowYSize - 80), static_cast<float>(windowXSize), 80.f, sf::Color(128, 128, 128));
    // Additional floating platforms
    platforms.emplace_back(200.f, static_cast<float>(windowYSize - 200), 250.f, 20.f, sf::Color::Blue);
    platforms.emplace_back(500.f, static_cast<float>(windowYSize - 350), 200.f, 20.f, sf::Color::Blue);
    platforms.emplace_back(900.f, static_cast<float>(windowYSize - 250), 150.f, 20.f, sf::Color::Blue);
    return platforms;
}

// Function to spawn a new wave of enemies
//void spawnWave(std::vector<std::unique_ptr<Enemy>>& enemies, int windowYSize, int waveNumber) {
//    int numberOfEnemies = waveNumber;
//    int startXPosition = 650;
//    int enemyXSize = 60.f;
//    int enemyYSize = 80.f;
//    int sizeBetweenSpawns = 200;
//    sf::Color enemyColor = sf::Color::Red;
//
//    switch (waveNumber) {
//    case 1:
//        numberOfEnemies = 3;
//        startXPosition = 650;
//        break;
//    case 2:
//        numberOfEnemies = 4;
//        startXPosition = 850;
//        enemyXSize = 40.f;
//        enemyYSize = 60.f;
//        enemyColor = sf::Color::Green;
//        sizeBetweenSpawns = 150;
//        break;
//    case 3:
//        numberOfEnemies = 5;
//        startXPosition = 850;
//        enemyXSize = 20.f;
//        enemyYSize = 80.f;
//        enemyColor = sf::Color::Green;
//        sizeBetweenSpawns = 75;
//        break;
//    default:
//        numberOfEnemies = 1;
//        startXPosition = 850;
//        enemyXSize = 100.f;
//        enemyYSize = 80.f;
//        enemyColor = sf::Color::Magenta;
//        sizeBetweenSpawns = 75;
//        break;
//    }
//
//    for (int i = 0; i < numberOfEnemies; ++i) {
//        // Create new enemies at different horizontal positions
//        enemies.push_back(std::make_unique<Enemy>(sf::Vector2f(enemyXSize, enemyYSize), enemyColor, startXPosition + i * sizeBetweenSpawns, windowYSize - 1000, 100, waveNumber * 100));
//        enemies.back()->setSpeed(2 + waveNumber * 0.4); // Increase enemy speed with each wave
//
//    }
//}

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
    std::vector<Platform> platforms = createPlatforms(windowXSize, windowYSize);

    // Create game state machine
    Game game;

    // Create Pause Menu
    //PauseMenu pauseMenu(800, 600);

    //// Create our main character using the new Character class and set offset and speed
    //Character player("Assets/Character/Idle/idle.png",
    //    "Assets/Character/Run/Run-Sheet.png",
    //    "Assets/Character/Run/Run-Sheet-Back.png",
    //    "Assets/Character/Jumlp-All/Jump-All-Sheet.png",
    //    "Assets/Character/Attack-01/Attack-01-Sheet.png",
    //    350, 400, 15, 30); // defaultYOffset, attackYOffset
    //player.setSpeed(6);
    //player.snapToPlatform(platforms[0]);

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

    //game.setState(Running);

    while (window.isOpen())
    {

        sf::Event event;

        // Get inputs
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    //    // Game State
    //    switch (game.getState()) {
    //    case Running:
    //    {
    //        // Jump
    //        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
    //            player.jump();
    //        }
    //        if (event.type == sf::Event::JoystickButtonPressed && event.joystickButton.joystickId == 0 && event.joystickButton.button == 0) {
    //            player.jump();
    //        }

    //        // Attack
    //        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::X) {
    //            player.attack();
    //        }
    //        if (event.type == sf::Event::JoystickButtonPressed && event.joystickButton.joystickId == 0 && event.joystickButton.button == 2) {
    //            player.attack();
    //        }

    //        // Throw Ball
    //        if (event.type == sf::Event::JoystickButtonPressed && event.joystickButton.joystickId == 0 && event.joystickButton.button == 1) {
    //            Balls.push_back(player.shootBall());
    //        }

    //        // Pause the game
    //        if (event.type == sf::Event::JoystickButtonPressed && event.joystickButton.joystickId == 0 && event.joystickButton.button == 7) {
    //            if (game.getState() == Running) {
    //                game.setState(Paused);
    //            }
    //            else {
    //                game.setState(Running);
    //            }

    //        }
    //        // Check for player attack
    //        if (player.isAttacking() && !player.hasHit()) {
    //            for (auto& enemy : enemies) {
    //                if (enemy->getHealth() > 0) {
    //                    if (player.getAttackBounds().intersects(enemy->getBounds())) {
    //                        std::cout << "Enemy hit! Health: " << enemy->getHealth() << std::endl;
    //                        enemy->takeDamage(10);
    //                        player.setHasHit(true); // Set the flag to prevent repeated hits
    //                        break; // Stop checking after the first hit
    //                    }
    //                }
    //            }
    //        }

    //        // Player collision with enemy for damage and knockback
    //        if (!player.isAttacking()) {
    //            for (auto& enemy : enemies) {
    //                if (enemy->getHealth() > 0) {
    //                    if (player.getBounds().intersects(enemy->getBounds())) {
    //                        player.takeDamage(10, enemy->getBounds().left);
    //                    }
    //                }
    //            }
    //        }

    //        // Update the player character
    //        player.update(window, platforms);

    //        // Update all enemies and pass a reference to the player for AI
    //        for (auto& enemy : enemies) {
    //            enemy->update(window, platforms, player);
    //        }

    //        // Update all Balls
    //        for (auto& Ball : Balls) {
    //            Ball->update(platforms);
    //        }

    //        // Check for Ball collisions with enemies
    //        for (auto& Ball : Balls) {
    //            if (!Ball->isExploding()) {
    //                for (auto& enemy : enemies) {
    //                    if (enemy->getBounds().intersects(Ball->getBounds())) {
    //                        enemy->takeDamage(10); // Ball deals more damage
    //                        Ball->explode();
    //                    }
    //                }
    //            }
    //            else {
    //                // Check if the explosion hits other enemies
    //                for (auto& enemy : enemies) {
    //                    if (enemy->getBounds().intersects(Ball->getExplosionBounds())) {
    //                        enemy->takeDamage(5); // Splash damage
    //                    }
    //                }
    //            }
    //        }

    //        // Use the Erase-Remove Idiom for C++17 compatibility.
    //        enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [](const std::unique_ptr<Enemy>& enemy) {
    //            return enemy->getHealth() <= 0;
    //            }), enemies.end());

    //        // Remove Balls that have finished their explosion animation
    //        Balls.erase(std::remove_if(Balls.begin(), Balls.end(), [](const std::unique_ptr<Ball>& Ball) {
    //            return Ball->isFinished();
    //            }), Balls.end());

    //        // Check if the wave is defeated
    //        if (enemies.empty()) {
    //            std::cout << "Wave " << currentWave << " defeated! Spawning next wave." << std::endl;
    //            game.incDecGold(10 * currentWave);
    //            currentWave++;
    //            spawnWave(enemies, window.getSize().y, currentWave);
    //        }

    //        window.clear();

    //        // Draw game values
    //        game.updateGameDisp(window);

    //        // Draw all platforms
    //        for (const auto& platform : platforms) {
    //            window.draw(platform.shape);
    //        }

    //        // Draw the player
    //        player.draw(window);

    //        // Draw all enemies and their health bars
    //        for (auto& enemy : enemies) {
    //            enemy->draw(window);
    //            enemy->drawHealthBar(window);
    //        }

    //        // Draw all Balls
    //        for (auto& Ball : Balls) {
    //            Ball->draw(window);
    //        }

    //        // Draw the player's health bar
    //        player.drawHealthBar(window);

    //        window.display();
    //        break;
    //    }

    //    case Paused:

    //        // Redraw last Running state
    //        for (const auto& platform : platforms) {
    //            window.draw(platform.shape);
    //        }

    //        // Draw the player
    //        player.draw(window);

    //        // Draw all enemies and their health bars
    //        for (auto& enemy : enemies) {
    //            enemy->draw(window);
    //            enemy->drawHealthBar(window);
    //        }

    //        // Draw all Balls
    //        for (auto& Ball : Balls) {
    //            Ball->draw(window);
    //        }

    //        // Draw the player's health bar
    //        player.drawHealthBar(window);

    //        // Draw game values
    //        game.updateGameDisp(window);

    //        // Update the game state based on menu input.
    //        game.setState(pauseMenu.handleInput(window));

    //        // Draw the pause menu over the game.
    //        pauseMenu.draw(window);

    //        window.display();

    //        break;
    //    default:
    //        break;
    //    }

    //}

    return 0;
}
