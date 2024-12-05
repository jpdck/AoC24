/*
Advent of Code: Day 4

Part 1:
The input is a block of text, with an indeterminate number of lines and characters.
We need to find the number of times the word 'XMAS' appears in the text.
The word can be in any direction, including diagonally.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

bool isValid(int x, int y, int rows, int cols)
{
    return (x >= 0 && x < rows && y >= 0 && y < cols);
}

bool searchDirection(const std::vector<std::vector<char>> &grid, const std::string &word,
                     int x, int y, int dx, int dy)
{
    int rows = grid.size();
    int cols = grid[0].size();
    int word_length = word.length();

    int endX = x + (word_length - 1) * dx;
    int endY = y + (word_length - 1) * dy;
    if (!isValid(endX, endY, rows, cols))
    {
        return false;
    }

    for (int i = 0; i < word_length; i++)
    {
        int curX = x + i * dx;
        int curY = y + i * dy;
        if (grid[curX][curY] != word[i])
        {
            return false;
        }
    }
    return true;
}

int find_word(const std::vector<std::vector<char>>& grid, const std::string& word) {
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;
    
    std::vector<std::pair<int, int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},           {0, 1},
        {1, -1},  {1, 0},  {1, 1}
    };
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (const auto& dir : directions) {
                if (searchDirection(grid, word, i, j, dir.first, dir.second)) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main()
{

    std::ifstream file("input.txt");
    std::string line;
    std::vector<std::vector<char>> grid;
    int count = 0;

    while (getline(file, line)) {
        if (!line.empty()) {
            std::vector<char> row(line.begin(), line.end());
            grid.push_back(row);
        }
    }

    file.close();

    std::string word = "XMAS";

    std::cout << "Found " << find_word(grid, word) << " occurrences of the word '" << word << "'." << std::endl;

    return 0;
}