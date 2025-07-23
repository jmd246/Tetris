#ifndef TETROMINO_HPP
#define TETROMINO_HPP

#include <SFML/Graphics.hpp>

class Tetromino {
public:
    int shape[4][4];            // 4x4 grid representing the tetromino
    sf::Vector2i position;      // Position on the board (in grid units)
    sf::Color color;            // Color of the tetromino

    Tetromino(const int shapeData[4][4], sf::Vector2i startPos, sf::Color color);
    void draw(sf::RenderWindow& window, float blockSize);
};

#endif // TETROMINO_HPP
