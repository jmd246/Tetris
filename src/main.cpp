#include <SFML/Graphics.hpp>
#include "Tetromino.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 400, 400 }), "SFML works!");
    int IShape[4][4] = {
      {1, 1, 1, 1},
      {1, 1, 1, 1},
      {1, 1, 1, 1},
      {1, 1, 1, 1}
    };
    int vector[] = {3,3};
    Tetromino tetromino(IShape, { vector[0], vector[1]}, sf::Color::Cyan);


    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::White);
        tetromino.draw(window,10);
        window.display();
    }
    return 0;
}