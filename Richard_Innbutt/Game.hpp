#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp> // Include necessary SFML headers
#include <iostream>
#include <string>

// A class for the state of the game
class Game {
private:
    int enemiesDefeated;
    int gold;
    int state;
    sf::Text goldText;
    sf::Font font;

public:
    Game(); // Constructor declaration

    void setState(int stateCMD);
    int getState();

    void incDecGold(int changeAmount);
    int getGold();

    // Updates gold text and other game state variables
    void updateGameDisp(sf::RenderWindow& window);
};

#endif // GAME_H