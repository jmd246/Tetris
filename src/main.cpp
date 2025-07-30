#include <SFML/Graphics.hpp>
#include   "TetrominoFactory.hpp"
#include "Board.hpp"
int main()
{

    sf::RenderWindow window(sf::VideoMode({ 400, 400 }), "Tetris!");

    const float blockSize = 15.0f;
    const float fallDelay = 0.5f;
    int dy = 1;


    Board  board;
    Tetromino   active = TetrominoFactory::getInstance().generateTetromino('i');

    sf::Clock fallTimer;


    
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // === Gravity Logic ===
        if (fallTimer.getElapsedTime().asSeconds() >= fallDelay) {
            
            if (board.canMove(active, { 0, dy })) {
                active.position.y += dy;
            }
            else {
                board.lockTetromino(active);
                active = TetrominoFactory::getInstance().randomTetromino(); // Next piece
            }
            

            fallTimer.restart();
        }

        // === Render ===
        window.clear();
        board.draw(window,blockSize);
        active.draw(window,blockSize); // draw active piece above board
        window.display();
    }
    return 0;
}