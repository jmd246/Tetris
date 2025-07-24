#include <SFML/Graphics.hpp>
#include   "TetrominoFactory.hpp"
int main()
{
    sf::RenderWindow window(sf::VideoMode({ 400, 400 }), "Tetris!");
    
  
    TetrominoFactory::getInstance().generateTetromino('i');
    TetrominoFactory::getInstance().generateTetromino('o');
    TetrominoFactory::getInstance().generateTetromino('t');
    TetrominoFactory::getInstance().generateTetromino('s');
    TetrominoFactory::getInstance().generateTetromino('z');
    TetrominoFactory::getInstance().generateTetromino('l');
    TetrominoFactory::getInstance().generateTetromino('j');




    
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::White);
        for (Tetromino tetromino : TetrominoFactory::getInstance().getList()) {
            tetromino.draw(window, 10);
        }
        window.display();
    }
    return 0;
}