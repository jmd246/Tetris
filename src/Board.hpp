#ifndef BOARD_HPP
#define	BOARD_HPP
#include	<vector>
class Board
{
public:
	Board() {
		//vector	of	size	heigth	of	vectors	of	size	width	all	elements	set	to	0
		grid = std::vector<srd::vector<int>>(height, std::vector<int>(width), 0);
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
        for (int col = 0; col < width; ++col) {
            grid[row][col] = 0;
        }
    }
    void dropLines() {
        for (int row = height - 1; row >= 0; --row) {
            bool full = true;
            for (int col = 0; col < width; ++col) {
                if (grid[row][col] == 0) {
                    full = false;
                    break;
                }
            }

            if (full) {
                // Drop all rows above down by 1
                for (int r = row; r > 0; --r) {
                    grid[r] = grid[r - 1];
                }
                grid[0] = std::vector<int>(width, 0); // topmost row is now empty
                row++; // recheck this row again after dropping
            }
        }
    }

    void reset() {
        for (auto& row : grid)
            std::fill(row.begin(), row.end(), 0);
    }
private:
	const int width = 10, height = 22;
	std::vector<std::vector<int>>	grid;
};

#endif // !BOARD_HPP
