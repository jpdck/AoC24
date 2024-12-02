/*
Advent of Code: Day 2

Part 1:
For each line in the input, determine if the values are:
- Increasing or decreasing in value
- Has a difference in value between 1 and 3, inclusive

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <sstream>

bool isValidDiff(int a, int b)
{
    int diff = std::abs(a - b);
    if (diff < 1 || diff > 3)
        std::cout << "DIFF [" << std::to_string(diff) << "] [" << std::to_string(b) << "] [" << std::to_string(a) << "]" << std::endl;

    return diff >= 1 && diff <= 3;
}

int main()
{
    std::ifstream input("input.txt");
    std::string line;
    int safe_reports = 0;

    while (std::getline(input, line))
    {
        std::vector<int> nums;
        std::istringstream iss(line);
        int num;
        int direction = 0;
        bool valid = true;

        while (iss >> num)
            nums.push_back(num);

        if (nums.size() < 2)
            continue;

        for (size_t i = 1; i < nums.size() && valid; i++)
        {
            valid = isValidDiff(nums.at(i), nums.at(i - 1));

            if (!valid)
                break;
                
            if (direction == 0)
                direction = nums.at(i) > nums.at(i - 1) ? 1 : 2;

            else if (direction == 1 && nums.at(i) < nums.at(i - 1))
            {
                std::cout << "CDIR [+1 -1] [" + std::to_string(nums.at(i - 1)) + "] [" + std::to_string(nums.at(i)) + "] [" << line << "]" << std::endl;
                valid = false;
                break;
            }
            else if (direction == 2 && nums.at(i) > nums.at(i - 1))
            {
                std::cout << "CDIR [-1 +1] [" + std::to_string(nums.at(i - 1)) + "] [" + std::to_string(nums.at(i)) + "] [" << line << "]" << std::endl;
                valid = false;
                break;
            }
        }

        safe_reports += valid;
    }

    std::cout << "Safe Reports: " << safe_reports << std::endl;

    return 0;
}