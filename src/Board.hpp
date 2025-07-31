#ifndef BOARD_HPP
#define	BOARD_HPP
#include	<vector>
#include   "Tetromino.hpp"
class Board
{
public:
	Board() {
		//vector	of	size	heigth	of	vectors	of	size	width	all	elements	set	to	0
		grid = std::vector<std::vector<char>>(height, std::vector<char>(width,'~'));
	}
    int getCell(int row, int col) const {
        return grid[row][col];
    }

    void setCell(int row, int col, int value) {
        grid[row][col] = value;
    }

    bool isInside(int row, int col) const {
        return row >= 0 && row < height && col >= 0 && col < width;
    }

    bool isEmpty(int row, int col) const {
        return isInside(row, col) && grid[row][col] == 0;
    }
    void clearLine(int row) {
        //sets elements in a row to zero  
        for (int col = 0; col < width; ++col) {
            grid[row][col] = 0;
        }
    }
    void dropLines() {
        for (int row = height - 1; row >= 0; --row) {
            bool full = true;
            for (int col = 0; col < width; ++col) {
                if (grid[row][col] == '~') {
                    full = false;
                    break;
                }
            }

            if (full) {
                // Drop all rows above down by 1
                for (int r = row; r > 0; --r) {
                    grid[r] = grid[r - 1];
                }
                grid[0] = std::vector<char>(width, '~'); // topmost row is now empty
                row++; // recheck this row again after dropping
            }
        }
    }
    void reset() {
        for (auto& row : grid)
            std::fill(row.begin(), row.end(), '~');
    }
    bool    canMove(const Tetromino& t, sf::Vector2i delta) const {
        for (int row = 0; row < 4; ++row) {
            for (int col = 0; col < 4; ++col) {
                if (t.shape[row][col] == 0) continue;

                int newX = t.position.x + col + delta.x;
                int newY = t.position.y + row + delta.y;

                // Check bounds
                if (newX < 0 || newX >= width || newY < 0 || newY >= height)
                    return false;

                // Check for collision with placed blocks
                if (grid[newY][newX] != '~')
                    return false;
            }
        }
        return true;
    }
    void  lockTetromino(const Tetromino& tetro) {
        for (int row = 0; row < 4; ++row) {
            for (int col = 0; col < 4; ++col) {
                if (tetro.shape[row][col]) {
                    int x = tetro.position.x + col;
                    int y = tetro.position.y + row;

                    if (x >= 0 && x < width && y >= 0 && y < height) {
                        // using int:
                        //grid[y][x] = 1;

                        // Or if using char-based grid:
                        grid[y][x] = tetro.shapeLetter;
                    }
                }
            }
        }
    }

    sf::Color getColor(int x,int  y) {
        char  type = grid[y][x];
        switch (type)
        {
            case    'i':
                return  sf::Color::Cyan;
            case    'o':
                return  sf::Color::Yellow;
            case    's':
                return  sf::Color::Green;
            case    't': {
                sf::Color  purple = sf::Color(128, 0, 128);
                return  purple;
            }
            case    'z':
                return  sf::Color::Red;
            case    'l': {
                sf::Color orange = sf::Color(256, 165, 0);
                return  orange;
            }
            case    'j':
                return  sf::Color::Blue;
            default: {
                sf::Color gray = sf::Color(100, 100, 100);
                return  gray; 
            }
        }

    }

    void draw(sf::RenderWindow& window, float blockSize) {
        sf::RectangleShape block(sf::Vector2f(blockSize, blockSize));
        block.setOutlineThickness(-1);
        block.setOutlineColor(sf::Color::Black);
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                if (grid[y][x]) {
                    block.setFillColor(getColor(x,y)); // Default gray for filled blocks
                    block.setPosition({ x * blockSize, y * blockSize });
                    window.draw(block);
                }
            }
        }
    }

    //set   piece
    //input tetrimino 
    /*
       check if top 4 rows are free spwan piece  
    */
    //updatePos 
    /*
       tick system that is frame independent . every 300ms mpve piece down a row 
    */


private:
	const int width = 10, height = 22;
	std::vector<std::vector<char>>	grid;
};

#endif // !BOARD_HPP
