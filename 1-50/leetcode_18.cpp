#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        if (nums.size() < 4)
        {
            return {};
        }

        sort(nums.begin(), nums.end());

        if (nums[0] > target && nums[0] > 0)
        {
            return {};
        }

        set<vector<int>> res;

        for (int i = 0; i < nums.size() - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                for (int k = j + 1; k < nums.size() - 1; k++)
                {
                    if (k > j + 1 && nums[k] == nums[k - 1])
                        continue;
                    for (int l = k + 1; l < nums.size(); l++)
                    {
                        if (l > k + 1 && nums[l] == nums[l - 1])
                            continue;
                        long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[l];
                        if (sum == (long long)target)
                        {
                            vector<int> temp{nums[i], nums[j], nums[k], nums[l]};
                            res.insert(temp);
                        }
                    }
                }
            }
        }

        return vector<vector<int>>(res.begin(), res.end());
    }
};