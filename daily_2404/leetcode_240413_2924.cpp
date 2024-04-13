#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
    int findChampion(int n, vector<vector<int>> &edges)
    {
        vector<int> vec(n,1);
        for(auto edge:edges)
        {
            if(vec[edge[1]]==1) vec[edge[1]]--;
        }
        if(accumulate(vec.begin(),vec.end(),0)!=1)
        {
            return -1;
        }
        for(int i=0;i<n;i++)
        {
            if(vec[i]==1) return i;
        }
        return -1;
    }
};