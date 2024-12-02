#!/bin/bash

# Create 25 day folders with their contents
for i in {1..25}; do
    # Format day number with leading zero
    day_num=$(printf "day%02d" $i)
    
    # Create directory
    mkdir -p $day_num
    
    # Create empty main.cpp with basic structure
    touch $day_num/main.cpp
    
    # Create empty input.txt
    touch $day_num/input.txt
done

echo "Created folders for 25 days of Advent of Code!"
echo "Each folder contains:"
echo "  - main.py (empty)"
echo "  - input.txt (empty)"
echo ""
echo "To compile and run a day's solution:"
echo "  cd day01"
echo "  clang++ -std=c++17 main.cpp -o solution"
echo "  ./solution"