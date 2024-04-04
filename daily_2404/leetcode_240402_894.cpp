#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<TreeNode *> allPossibleFBT(int n)
    {
        if (n % 2 == 0)
            return {};
        if (n == 1)
            return {new TreeNode()};

        vector<TreeNode *> result = {};

        for (int i = 1; i < n; i += 2)
        {
            auto l_trees = allPossibleFBT(i);
            auto r_trees = allPossibleFBT(n - 1 - i);
            for (auto l : l_trees)
            {
                for (auto r : r_trees)
                {
                    result.push_back(new TreeNode(0, l, r));
                }
            }
        }

        return result;
    }
};