/*
Advent of Code: Day 3

Part 1:
The goal of the program is to multiply some numbers
and then find the sum of the results. However, the
input is a corrupted mess. We need to clean it up and look
for instructions mul(a, b) and only mul(a, b).

Part 2:
There are do() and don't() instructions that can be used
to control whether the program should multiply numbers or not.
Find these instructions that are intermixed in the input and use
them to control the multiplication process.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <regex>

const std::regex pattern(R"(mul\(([0-9]+),([0-9]+)\))");

int main()
{
    std::ifstream file("input.txt");
    std::string line;
    int sum = 0;
    bool do_work = true;

    line = std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    std::smatch match;
    std::regex pattern(R"(mul\(([0-9]+),([0-9]+)\)|do\(\)|don't\(\))");
    std::string::const_iterator search_start(line.cbegin());

    while (std::regex_search(search_start, line.cend(), match, pattern))
    {
        std::string found = match[0];

        if (found.substr(0, 3) == "mul" && do_work)
        {
            // Handle multiplication case
            int num1 = std::stoi(match[1]);
            int num2 = std::stoi(match[2]);
            int product = num1 * num2;
            sum += product;
        }
        else if (found == "do()")
        {
            do_work = true;
        }
        else if (found == "don't()")
        {
            do_work = false;
        }
        search_start = match.suffix().first;
    }

    std::cout << "Sum of all matches: " << sum << std::endl;
    return 0;
}