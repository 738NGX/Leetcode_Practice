#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int size = nums.size();

        if (size < 3)
        {
            return {};
        }

        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int left = 0; left < size - 2; left++)
        {
            if (left > 0 && nums[left - 1] == nums[left])
            {
                continue;
            }

            int mid=left+1,right=size-1;

            while(mid<right)
            {
                int sum=nums[left]+nums[mid]+nums[right];

                if(sum==0)
                {
                    result.push_back({nums[left],nums[mid],nums[right]});
                    
                    while(mid<right && nums[right-1]==nums[right]) right--;
                    while(mid<right && nums[mid+1]==nums[mid]) mid++;

                    right--;
                    mid++;
                    continue;
                }
                else if(sum<0)
                {
                    mid++;
                }
                else
                {
                    right--;
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<int> v={0,0,0};
    s.threeSum(v);
    return 0;
}