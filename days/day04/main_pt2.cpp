/*
Advent of Code: Day 4

Part 2:
Find all occurrences of:
[ M * S ]
[ * A * ]
[ M * S ]

Where M, A, S, X are characters in the grid and * can be any character

We need to find all occurrences of a "MAS"-X pattern in the grid. It's where 2 MAS form an X in the grid.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{

    std::ifstream file("input.txt");
    std::string line;
    std::vector<std::vector<char>> grid;
    int count = 0;

    while (getline(file, line))
    {
        if (!line.empty())
        {
            std::vector<char> row(line.begin(), line.end());
            grid.push_back(row);
        }
    }

    file.close();

    // loop through the grid and check:
    // 1. If and where we are out of bounds
    // 2. If we have a "MAS" pattern

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            // Do we have an M?
            if (grid[i][j] != 'M')
            {
                continue;
            }

            // Check if we have a matching M in one of the four directions
            // 1. Right
            if (j + 2 < grid[i].size() && grid[i][j + 2] == 'M')
            {
                // Check if we have an A below
                if (i + 1 < grid.size() && grid[i + 1][j + 1] == 'A')
                {
                    // Check if we have an S below
                    if ((i + 2 < grid.size() && grid[i + 2][j] == 'S') &&
                        (i + 2 < grid.size() && grid[i + 2][j + 2] == 'S'))
                    {
                        count++;
                    }
                }
                // Check if we have an A above
                if (i - 1 >= 0 && grid[i - 1][j + 1] == 'A')
                {
                    // Check if we have an S above
                    if ((i - 2 >= 0 && grid[i - 2][j] == 'S') &&
                        (i - 2 >= 0 && grid[i - 2][j + 2] == 'S'))
                    {
                        count++;
                    }
                }
            }

            // 2. Left
            if (j - 2 >= 0 && grid[i][j - 2] == 'M')
            {
                // Check if we have an A above
                if (i - 1 >= 0 && grid[i - 1][j - 1] == 'A')
                {
                    // Check if we have an S above
                    if ((i - 2 >= 0 && grid[i - 2][j] == 'S') &&
                        (i - 2 >= 0 && grid[i - 2][j - 2] == 'S'))
                    {
                        count++;
                    }
                }

                // Check if we have an A below
                if (i + 1 < grid.size() && grid[i + 1][j - 1] == 'A')
                {
                    // Check if we have an S above
                    if ((i + 2 < grid.size() && grid[i + 2][j] == 'S') &&
                        (i + 2 < grid.size() && grid[i + 2][j - 2] == 'S'))
                    {
                        count++;
                    }
                }

            }
        
            // 3. Down
            if (i + 2 < grid.size() && grid[i + 2][j] == 'M')
            {
                // Check if we have an A to the right
                if (j + 1 < grid[i].size() && grid[i + 1][j + 1] == 'A')
                {
                    // Check if we have an S to the right
                    if ((j + 2 < grid[i].size() && grid[i][j + 2] == 'S') &&
                        (j + 2 < grid[i].size() && grid[i + 2][j + 2] == 'S'))
                    {
                        count++;
                    }
                }

                // Check if we have an A to the left
                if (j - 1 >= 0 && grid[i + 1][j - 1] == 'A')
                {
                    // Check if we have an S to the left
                    if ((j - 2 >= 0 && grid[i][j - 2] == 'S') &&
                        (j - 2 >= 0 && grid[i + 2][j - 2] == 'S'))
                    {
                        count++;
                    }
                }
            }

            // 4. Up
            if (i - 2 >= 0 && grid[i - 2][j] == 'M')
            {
                // Check if we have an A to the right
                if (j + 1 < grid[i].size() && grid[i - 1][j + 1] == 'A')
                {
                    // Check if we have an S to the right
                    if ((j + 2 < grid[i].size() && grid[i][j + 2] == 'S') &&
                        (j + 2 < grid[i].size() && grid[i - 2][j + 2] == 'S'))
                    {
                        count++;
                    }
                }

                // Check if we have an A to the left
                if (j - 1 >= 0 && grid[i - 1][j - 1] == 'A')
                {
                    // Check if we have an S to the left
                    if ((j - 2 >= 0 && grid[i][j - 2] == 'S') &&
                        (j - 2 >= 0 && grid[i - 2][j - 2] == 'S'))
                    {
                        count++;
                    }
                }
            }
        }
    }

    std::cout << "Count: " << count / 2 << std::endl;
    return 0;
}