#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        map<int,int> num_count;
        vector<int> wait_delete;

        for(int i=0;i<nums.size();i++)
        {
            if(num_count[nums[i]]==0)
            {
                num_count[nums[i]]+=1;
            }
            else
            {
                wait_delete.push_back(i);
            }
        }
        
        sort(wait_delete.begin(),wait_delete.end());

        for(int i=wait_delete.size()-1;i>=0;i--)
        {
            nums.erase(nums.begin()+wait_delete[i]);
        }

        return nums.size();
    }
};