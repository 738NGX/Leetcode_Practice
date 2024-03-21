#include<iostream>
#include<vector>

using namespace std;

class Solution 
{
public:
    int searchInsert(const vector<int>& nums,int target) 
    {
        int left=-1,right=nums.size();
        
        while(left+1!=right)
        {
            int mid=(right+left)/2;
            
            if(nums[mid]==target) 
                return mid;
            
            if(nums[mid]<target) 
                left=mid;
            else if(nums[mid]>target) 
                right=mid;
        }

        return right;
    }
};

int main()
{
    Solution s;
    cout<<s.searchInsert({1,3,5,6},2);
    return 0;
}