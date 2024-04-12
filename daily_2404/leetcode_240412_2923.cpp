#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findChampion(vector<vector<int>> &grid)
    {
        int champion = 0;
        int max = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            int count = 0;
            for (auto n : grid[i])
            {
                if (n == 1)
                    count++;
            }
            if (count > max)
            {
                max = count;
                champion = i;
            }
        }
        return champion;
    }
};