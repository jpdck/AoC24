/*
Advent of Code: Day 4

Part 1:
The input is a block of text, with an indeterminate number of lines and characters.
We need to find the number of times the word 'XMAS' appears in the text.
The word can be in any direction, including diagonally.

Part 2:
TBD.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{

    std::ifstream file("input.txt");
    std::string line;
    std::vector<std::vector<char>> grid;
    int count = 0;

    while (std::getline(file, line))
    {
        std::vector<char> row;
        for (char c : line)
        {
            row.push_back(c);
        }
        grid.push_back(row);
    }

    if (!grid.empty())
    {
        std::cout << "Grid size: " << grid.size() << " x " << grid[0].size() << std::endl;
    }
    else
    {
        std::cout << "Grid is empty." << std::endl;
    }

    std::string word = "XMAS";
    for (size_t i = 0; i < grid.size(); i++)
    {
        const std::vector<char> &row = grid[i];
        for (size_t j = 0; j < row.size(); j++)
        {
            if (row[j] == 'X')
            {
                // Check right
                if (j + (word.size() - 1) < row.size())
                {
                    bool match = true;
                    for (size_t k = 0; k < word.size(); k++)
                    {
                        if (row[j + k] != word[k])
                        {
                            match = false;
                            break;
                        }
                    }

                    count += match ? 1 : 0;
                }

                // Check down
                if (i + (word.size() - 1) < grid.size())
                {
                    bool match = true;
                    for (size_t k = 0; k < word.size(); k++)
                    {
                        if (grid[i + k][j] != word[k])
                        {
                            match = false;
                            break;
                        }
                    }

                    count += match ? 1 : 0;
                }

                // Check down-right
                if (i + (word.size() - 1) < grid.size() && j + (word.size() - 1) < row.size())
                {
                    bool match = true;
                    for (size_t k = 0; k < word.size(); k++)
                    {
                        if (grid[i + k][j + k] != word[k])
                        {
                            match = false;
                            break;
                        }
                    }

                    count += match ? 1 : 0;
                }

                // Check down-left
                if (i + (word.size() - 1) < grid.size() && j - (word.size() - 1) >= 0)
                {
                    bool match = true;
                    for (size_t k = 0; k < word.size(); k++)
                    {
                        if (grid[i + k][j - k] != word[k])
                        {
                            match = false;
                            break;
                        }
                    }

                    count += match ? 1 : 0;
                }

                // Check up-right
                if (i - (word.size() - 1) >= 0 && j + (word.size() - 1) < row.size())
                {
                    bool match = true;
                    for (size_t k = 0; k < word.size(); k++)
                    {
                        if (grid[i - k][j + k] != word[k])
                        {
                            match = false;
                            break;
                        }
                    }

                    count += match ? 1 : 0;
                }

                // Check up-left
                if (i - (word.size() - 1) >= 0 && j - (word.size() - 1) >= 0)
                {
                    bool match = true;
                    for (size_t k = 0; k < word.size(); k++)
                    {
                        if (grid[i - k][j - k] != word[k])
                        {
                            match = false;
                            break;
                        }
                    }

                    count += match ? 1 : 0;
                }

                // Check up
                if (i - (word.size() - 1) >= 0)
                {
                    bool match = true;
                    for (size_t k = 0; k < word.size(); k++)
                    {
                        if (grid[i - k][j] != word[k])
                        {
                            match = false;
                            break;
                        }
                    }

                    count += match ? 1 : 0;
                }

                // Check left
                if (j - (word.size() - 1) >= 0)
                {
                    bool match = true;
                    for (size_t k = 0; k < word.size(); k++)
                    {
                        if (row[j - k] != word[k])
                        {
                            match = false;
                            break;
                        }
                    }

                    count += match ? 1 : 0;
                }
            }
        }
    }

    std::cout << "Found " << count << " occurrences of the word 'XMAS'." << std::endl;

    return 0;
}