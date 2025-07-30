#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Board.hpp"
#include "Tetromino.hpp"
#include "TetrominoFactory.hpp"
#include <memory>

class Game {
public:
    Game();
    void update();
    void draw(sf::RenderWindow& window);
    void handleInput(const sf::Event& event);

private:
    Board board;

    std::unique_ptr<Tetromino> currentPiece; // FIX: avoids default constructor issue
    sf::Clock gravityClock;
    float dropDelay = 0.5f; // gravity speed (in seconds)

    void spawnNewPiece();
    void lockPiece();
};

#endif
