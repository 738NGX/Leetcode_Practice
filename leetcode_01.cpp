#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    int p,q;
    bool end=0;
    vector<int> twoSum;
    for(p=0;p<nums.size()&&end==0;p++)
    {
        for(q=0;q<nums.size()&&end==0;q++)
        {
            if(nums[p]+nums[q]==target&&p!=q)
            {
                twoSum.push_back(p);
                twoSum.push_back(q); //符合条件，输出
                end=1; //结束循环
            }                
        }
    }
    return(twoSum);
    }
};