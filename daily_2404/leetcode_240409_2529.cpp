#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int num_pos = 0, num_neg = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
                num_neg++;
            else if (nums[i] > 0)
                num_pos++;
        }
        return max(num_neg,num_pos);
    }
};