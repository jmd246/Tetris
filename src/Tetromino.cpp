#include "Tetromino.hpp"

Tetromino::Tetromino(char shapeLetter,const int shapeData[4][4], sf::Vector2i startPos, sf::Color color)
    : shapeLetter(shapeLetter), position(startPos), color(color)
{
    state = INACTIVE;
    // Copy the 4x4 shape data
    for (int row = 0; row < 4; ++row)
        for (int col = 0; col < 4; ++col)
            shape[row][col] = shapeData[row][col];
}

void Tetromino::draw(sf::RenderWindow& window, float blockSize) {
    sf::RectangleShape block(sf::Vector2f(blockSize, blockSize));
    state = ACTIVE;
    block.setFillColor(color);
    block.setOutlineThickness(-1);
    block.setOutlineColor(sf::Color::Black);
    //travrse   a   4x4 checking    for on  positions 
    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            if (shape[row][col]) {
                block.setPosition(sf::Vector2f(
                    (position.x + col) * blockSize,
                    (position.y + row) * blockSize
                ));
                window.draw(block);
            }
        }
    }
}
