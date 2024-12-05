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

    while (getline(file, line)) {
        if (!line.empty()) {
            std::vector<char> row(line.begin(), line.end());
            grid.push_back(row);
        }
    }

    file.close();

    return 0;
}