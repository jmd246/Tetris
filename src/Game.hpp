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
    void play();
    void draw();
    void handleInput(const sf::Event& event);

private:
    Board board;
    sf::RenderWindow  window;
    sf::Clock gravityClock;
    float fallDelay = 0.5f; // gravity speed (in seconds)
    const float blockSize = 15.0f;
    int dy = 1;
    sf::Clock fallTimer;
    std::optional<Tetromino>  active;
    void spawnNewPiece();
    void lockPiece();
};

#endif
