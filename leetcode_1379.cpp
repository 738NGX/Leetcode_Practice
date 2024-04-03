#include <iostream>

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
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        if (!original)
            return nullptr;
        if (original == target)
            return cloned;
        auto left = getTargetCopy(original->left, cloned->left, target);
        auto right = getTargetCopy(original->right, cloned->right, target);
        return left ? left : right;
    }
};