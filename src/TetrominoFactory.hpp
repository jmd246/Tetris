#ifndef TETROMINO_FACTORY_HPP
#define TETROMINO_FACTORY_HPP
#include <cctype>
#include    <iostream>
#include "Tetromino.hpp"
class TetrominoFactory {
private:
    char letters[7] = { 'i','o','t','s','z','j','l' };
	


    TetrominoFactory() {}

	//delete assignment and copy operators to prevent duplication
	TetrominoFactory(const TetrominoFactory&) = delete;
	TetrominoFactory& operator=(const TetrominoFactory&) = delete;

public:
	static	TetrominoFactory& getInstance() {
		static	TetrominoFactory	instance;
		return	instance;
	}
	
	//IOTSZJL
    Tetromino   generateTetromino(char shapeLetter) {
        shapeLetter = std::tolower(shapeLetter);
        switch (shapeLetter)
        {
            case 'i': {
                int IShape[4][4] = {
                    {0, 0, 0, 0},
                    {1, 1, 1, 1},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0}
                };
                return  Tetromino::Tetromino(shapeLetter, IShape, { 3, 0 }, sf::Color::Cyan);
            }

            case 'o': {
                int OShape[4][4] = {
                    {0, 0, 0, 0},
                    {0, 1, 1, 0},
                    {0, 1, 1, 0},
                    {0, 0, 0, 0}
                };
                return  Tetromino::Tetromino(shapeLetter, OShape, { 3, 0 }, sf::Color::Yellow);
            }

            case 't': {
                int TShape[4][4] = {
                    {0, 0, 0, 0},
                    {1, 1, 1, 0},
                    {0, 1, 0, 0},
                    {0, 0, 0, 0}
                };
                return  Tetromino(shapeLetter, TShape, { 3, 0 }, sf::Color(128, 0, 128)); // Purple
            }

            case 'j': {
                int JShape[4][4] = {
                    {0, 0, 0, 0},
                    {1, 1, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0}
                };
                return  Tetromino(shapeLetter, JShape, { 3, 0 }, sf::Color::Blue);
            }

            case 'l': {
                int LShape[4][4] = {
                    {0, 0, 0, 0},
                    {1, 1, 1, 0},
                    {1, 0, 0, 0},
                    {0, 0, 0, 0}
                };
                return  Tetromino(shapeLetter, LShape, { 3, 0 }, sf::Color(255, 165, 0)); // Orange
            }

            case 's': {
                int SShape[4][4] = {
                    {0, 0, 0, 0},
                    {0, 1, 1, 0},
                    {1, 1, 0, 0},
                    {0, 0, 0, 0}
                };
                   return Tetromino(shapeLetter, SShape, { 3, 0 }, sf::Color::Green);
            }

            case 'z': {
                int ZShape[4][4] = {
                    {0, 0, 0, 0},
                    {1, 1, 0, 0},
                    {0, 1, 1, 0},
                    {0, 0, 0, 0}
                };
                return  Tetromino(shapeLetter, ZShape, { 3, 0 }, sf::Color::Red);
            }
        }
    }
    Tetromino   randomTetromino() {
        std::srand(std::time(nullptr));
        uint8_t randIndex = std::rand() % 7;
        std::cout << letters[randIndex];
        return  generateTetromino(letters[randIndex]);
    }

};


#endif // !1
