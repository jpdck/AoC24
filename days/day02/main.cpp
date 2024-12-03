#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

// Checks if differences between adjacent numbers are between 1 and 3
bool hasValidDifferences(const std::vector<int> &nums)
{
    for (size_t i = 1; i < nums.size(); i++)
    {
        int diff = std::abs(nums[i] - nums[i - 1]);
        if (diff < 1 || diff > 3)
            return false;
    }
    return true;
}

// Checks if sequence is monotonic (all increasing or all decreasing)
bool isMonotonic(const std::vector<int> &nums)
{
    if (nums.size() < 2)
        return true;

    bool increasing = nums[1] > nums[0];
    for (size_t i = 2; i < nums.size(); i++)
    {
        if ((nums[i] > nums[i - 1]) != increasing)
            return false;
    }
    return true;
}

// Checks if a sequence is safe according to basic rules
bool isBasicSafe(const std::vector<int> &nums)
{
    return nums.size() >= 2 &&
           hasValidDifferences(nums) &&
           isMonotonic(nums);
}

// Checks if sequence can be made safe by removing one number
bool isDampenerSafe(const std::vector<int> &nums)
{
    // First check if it's already safe without removing anything
    if (isBasicSafe(nums))
        return true;

    // Try removing each number one at a time
    for (size_t i = 0; i < nums.size(); i++)
    {
        std::vector<int> modified = nums;
        modified.erase(modified.begin() + i);

        // If removing this number makes the sequence safe, then it's dampener safe
        if (isBasicSafe(modified))
            return true;
    }

    return false;
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

        while (iss >> num)
        {
            nums.push_back(num);
        }

        // Using isDampenerSafe for Part 2
        if (isDampenerSafe(nums))
        {
            safe_reports++;
        }
    }

    std::cout << "Safe reports: " << safe_reports << std::endl;
    return 0;
}