#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int size = nums.size();
        int best_err = INT_MAX;
        sort(nums.begin(), nums.end());

        for (int left = 0; left < size - 2; left++)
        {
            if (left > 0 && nums[left - 1] == nums[left])
                left++;

            int mid = left + 1, right = size - 1;
            int err = INT_MAX;

            while (mid < right)
            {
                int current_sum = nums[left] + nums[mid] + nums[right];
                int current_err = current_sum - target;

                if (current_err == 0)
                    return target;

                if (abs(current_err) < abs(err))
                {
                    err = current_err;
                }

                if (current_err < 0)
                    mid++;
                else
                    right--;
            }

            if (abs(err) <= abs(best_err))
            {
                best_err = err;
            }
        }

        return target + best_err;
    }
};

int main()
{
    Solution s;
    vector<int> v = {-1000, -5, -5, -5, -5, -5, -5, -1, -1, -1};
    cout << s.threeSumClosest(v, -14);
    return 0;
}