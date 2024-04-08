#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int res = INT_MAX;

        for (int i = 0; i < nums.size(); i++)
        {
            int l = nums[i], r = l + nums.size() - 1;
            int this_res = 0;

            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j] < l || nums[j] > r)
                    this_res++;
                while (j < nums.size() - 1 && nums[j + 1] == nums[j])
                {
                    j++;
                    this_res++;
                }
            }

            if (this_res < res)
                res = this_res;
            if (res == 0)
                return 0;
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> vec = {4, 2, 5, 3};
    cout << s.minOperations(vec);
    return 0;
}