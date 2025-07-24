#ifndef TETROMINO_FACTORY_HPP
#define TETROMINO_FACTORY_HPP
#include <list>
#include <cctype>
#include "Tetromino.hpp"
class TetrominoFactory {
private:
	TetrominoFactory() {}
	std::list<Tetromino> tetrominos;

	//delete assignment and copy operators to prevent duplication
	TetrominoFactory(const TetrominoFactory&) = delete;
	TetrominoFactory& operator=(const TetrominoFactory&) = delete;

public:
	static	TetrominoFactory& getInstance() {
		static	TetrominoFactory	instance;
		return	instance;
	}
	std::list<Tetromino> getList() {
		return	tetrominos;
	}
	//IOTSZJL
    void generateTetromino(char shapeLetter) {
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
                tetrominos.push_back(Tetromino::Tetromino(shapeLetter, IShape, { 3, 24 }, sf::Color::Cyan));
                break;
            }

            case 'o': {
                int OShape[4][4] = {
                    {0, 0, 0, 0},
                    {0, 1, 1, 0},
                    {0, 1, 1, 0},
                    {0, 0, 0, 0}
                };
                tetrominos.push_back(Tetromino::Tetromino(shapeLetter, OShape, { 3, 21 }, sf::Color::Yellow));
                break;
            }

            case 't': {
                int TShape[4][4] = {
                    {0, 0, 0, 0},
                    {1, 1, 1, 0},
                    {0, 1, 0, 0},
                    {0, 0, 0, 0}
                };
                tetrominos.push_back(Tetromino::Tetromino(shapeLetter, TShape, { 3, 3 }, sf::Color(128, 0, 128))); // Purple
                break;
            }

            case 'j': {
                int JShape[4][4] = {
                    {0, 0, 0, 0},
                    {1, 1, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0}
                };
                tetrominos.push_back(Tetromino::Tetromino(shapeLetter, JShape, { 3, 6 }, sf::Color::Blue));
                break;
            }

            case 'l': {
                int LShape[4][4] = {
                    {0, 0, 0, 0},
                    {1, 1, 1, 0},
                    {1, 0, 0, 0},
                    {0, 0, 0, 0}
                };
                tetrominos.push_back(Tetromino::Tetromino(shapeLetter, LShape, { 3, 9 }, sf::Color(255, 165, 0))); // Orange
                break;
            }

            case 's': {
                int SShape[4][4] = {
                    {0, 0, 0, 0},
                    {0, 1, 1, 0},
                    {1, 1, 0, 0},
                    {0, 0, 0, 0}
                };
                tetrominos.push_back(Tetromino::Tetromino(shapeLetter, SShape, { 3, 15 }, sf::Color::Green));
                break;
            }

            case 'z': {
                int ZShape[4][4] = {
                    {0, 0, 0, 0},
                    {1, 1, 0, 0},
                    {0, 1, 1, 0},
                    {0, 0, 0, 0}
                };
                tetrominos.push_back(Tetromino::Tetromino(shapeLetter, ZShape, { 3, 12 }, sf::Color::Red));
                break;
            }
        }
    }

};


#endif // !1
