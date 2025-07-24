#ifndef TETROMINO_HPP
#define TETROMINO_HPP

#include <SFML/Graphics.hpp>
class  TetrominoFactroy;
class Tetromino {
private:
    friend class TetrominoFactory;
    enum State {
        ACTIVE, INACTIVE
    };
    char shapeLetter;
    State state;
    int shape[4][4];            // 4x4 grid representing the tetromino
    sf::Vector2i position;      // Position on the board (in grid units)
    sf::Color color;            // Color of the tetromino

    Tetromino(char shapeLetter,const int shapeData[4][4], sf::Vector2i startPos, sf::Color color);
public:
    void draw(sf::RenderWindow& window, float blockSize);
};

#endif // TETROMINO_HPP
