#include "Game.hpp" // Include the corresponding header file

Game::Game() {
    enemiesDefeated = 0;
    gold = 100;
    state = 0;

    if (!font.loadFromFile("Assets/Font/Roboto-Regular.ttf")) {
        std::cerr << "Failed to load font file: Assets/Font/Roboto-Regular.ttf" << std::endl;
    }
}

void Game::setState(int stateCMD) {
    state = stateCMD;
}

int Game::getState() {
    return state;
}

void Game::incDecGold(int changeAmount) {
    gold = gold + changeAmount;
}

int Game::getGold() {
    return gold;
}

void Game::updateGameDisp(sf::RenderWindow& window) {
    sf::FloatRect textRect = goldText.getLocalBounds();

    goldText.setFont(font);
    goldText.setCharacterSize(38);
    goldText.setFillColor(sf::Color::Yellow);
    goldText.setStyle(sf::Text::Bold);
    goldText.setString("Gold: " + std::to_string(gold));
    goldText.setOrigin(textRect.width, 0); // Set origin to the top-right of the text
    goldText.setPosition(window.getSize().x - 100, 100); // Position it 20 pixels from the right and 20 from the top

    // Draw gold count
    window.draw(goldText);
}