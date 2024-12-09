/*
Advent of Code: Day 5

Part 1:
We need to load up some rules from the input file.
Then we need to parse the "production line" and ensure all
the rules are followed.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

// RuleMap class handles storage and lookup of rules where one key can map to multiple values
class RuleMap
{
private:
    // Store mappings as key -> vector of values, allowing multiple values per key
    std::unordered_map<int, std::vector<int>> mappings;

public:
    void add_rule(int key, int value)
    {
        mappings[key].push_back(value);
    }

    const std::vector<int> &get_values(int key) const
    {
        static const std::vector<int> empty_vector;
        auto it = mappings.find(key);
        return (it != mappings.end()) ? it->second : empty_vector;
    }

    void print_mappings() const
    {
        for (const auto &[key, values] : mappings)
        {
            std::cout << key << " maps to: ";
            for (int value : values)
            {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
    }

    // Get the total number of rules (counting all value mappings)
    size_t total_rules() const
    {
        size_t total = 0;
        for (const auto &[key, values] : mappings)
        {
            total += values.size();
        }
        return total;
    }
};

int main()
{
    std::ifstream file("input.txt");
    std::string line;
    RuleMap rules;
    bool processing_rules = true;
    std::vector<std::vector<int>> updates;
    int line_number = 1;

    while (getline(file, line))
    {
        std::cout << "Processing Line[" << line_number << "]: " << line << std::endl;
        if (line.empty())
        {
            if (processing_rules && rules.total_rules() > 0)
            {
                processing_rules = false;
            }
            continue;
        }

        // Only process lines while we're in the rules section
        if (processing_rules)
        {
            size_t delimiter_pos = line.find('|');

            if (delimiter_pos != std::string::npos)
            {
                int key = std::stoi(line.substr(0, delimiter_pos));
                int value = std::stoi(line.substr(delimiter_pos + 1));
                rules.add_rule(key, value);
            }
            else
            {
                processing_rules = false;
            }
        }
        else
        {
            // std::cout << "Processing Line[" << line_number << "]: " << line << std::endl;
            std::string current_number = "";
            std::vector<int> numbers;
            for (char c : line)
            {
                if (c == ',')
                {
                    if (!current_number.empty())
                    {
                        numbers.push_back(std::stoi(current_number));
                        current_number.clear();
                    }
                }
                else if (std::isdigit(c))
                {
                    current_number += c;
                }
            }

            for (int i = 0; i < numbers.size(); i++)
            {
                bool fail = false;
                int current_rule = numbers[i];
                std::vector<int> values = rules.get_values(current_rule);

                if (values.size() == 0)
                {
                    break;
                }
                for (int j = 0; j < numbers.size(); j++)
                {
                    auto it = std::find(values.begin(), values.end(), numbers[j]);
                    size_t pos = values.end() - it;
                    if (pos < i)
                    {
                        fail = true;
                        break;
                    }
                }

                if (fail)
                {
                    break;
                }

                // Print the midpoint of the update
                std::cout << "Midpoint of current update: [" << numbers.at(numbers.size() / 2) << "]" << std::endl;
            }

            line_number++;
        }
    }

    file.close();
    return 0;
}