/*
Advent of Code Day 1

Part 1:
Pair up the smallest number in the "left" list with the
smallest number in the "right" list, and so on. Within
each pair, figure out how far apart the two numbers are.
The answer to Part 1  is the sum of all of these distances.

Part 2:
TBD


*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>

int main() {
    std::ifstream input("input.txt");
    std::string line;
    std::vector<int> left_nums;
    std::vector<int> right_nums;
    int running_sum = 0;
    int similarity_score = 0;

    while(std::getline(input, line)){
        int left = std::stoi(line.substr(0, line.find(' ')));
        int right = std::stoi(line.substr(line.find(' ') + 1));
        right_nums.push_back(right);
        left_nums.push_back(left);
    }

    
    for(const auto& left_num : left_nums){
        int appearances = std::count(right_nums.begin(), right_nums.end(), left_num);
        similarity_score += left_num * appearances;
    }

    std::sort(left_nums.begin(), left_nums.end());
    std::sort(right_nums.begin(), right_nums.end());

    for(int i = 0; i < 1000; i++){
        running_sum += std::abs(right_nums.at(i) - left_nums.at(i));
    }

    std::cout << "Final Distance:   " << running_sum << std::endl;
    std::cout << "Similarity Score: " << similarity_score << std::endl;
}