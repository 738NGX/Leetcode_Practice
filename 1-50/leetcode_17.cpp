#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution
{
public:
    map<char, vector<char>> digit_char_map =
        {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}},
    };

    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
        {
            return {};
        }

        vector<string> res = {""};
        vector<string> new_res;

        for (int i = 0; i < digits.size(); i++)
        {
            auto digit = digits[i];
            auto char_map = digit_char_map[digit];

            for (auto str : res)
            {
                for (auto ch : char_map)
                {
                    new_res.push_back(str + ch);
                }
            }

            res = new_res;
            new_res.clear();
        }

        return res;
    }
};