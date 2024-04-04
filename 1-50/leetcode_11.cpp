#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0, r = height.size() - 1;

        int max_capacity = (r - l) * min(height[l], height[r]);

        while (l < r)
        {
            if (height[l] <= height[r])
            {
                while (l < r && height[l + 1] < height[l])
                    l++;
                l++;
            }
            else
            {
                while (l < r && height[r - 1] < height[r])
                    r--;
                r--;
            }
            int new_capacity = (r - l) * min(height[l], height[r]);
            if (new_capacity < max_capacity)
                continue;
            max_capacity = new_capacity;
        }

        return max_capacity;
    }
};