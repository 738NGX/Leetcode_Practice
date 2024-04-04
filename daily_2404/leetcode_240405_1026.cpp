#include <iostream>
#include <cmath>
#include <stack>

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
    int maxAncestorDiff(TreeNode *root)
    {
        int maxDiff = 0;
        dfs(root, root->val, root->val, maxDiff);
        return maxDiff;
    }

    void dfs(TreeNode *node, int curMax, int curMin, int &maxDiff)
    {
        if (!node)
            return;

        curMax = max(curMax, node->val);
        curMin = min(curMin, node->val);

        maxDiff = max(maxDiff, abs(curMax - curMin));

        dfs(node->left, curMax, curMin, maxDiff);
        dfs(node->right, curMax, curMin, maxDiff);
    }
};