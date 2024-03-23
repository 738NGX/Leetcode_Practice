#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    class Node
    {
    private:
        int val;
        int push_count;
        int push_limit;
 
    public:
        string str;
        Node *left;
        Node *right;

        Node(int v, int c, int l, const string s) : val(v),
                                                    push_count(c),
                                                    push_limit(l),
                                                    str(s),
                                                    left(nullptr),
                                                    right(nullptr)
        {
        }

        void Grow()
        {
            left = push_count < push_limit ? new Node(val + 1, push_count + 1, push_limit, str + "(") : nullptr;
            right = val > 0 ? new Node(val - 1, push_count, push_limit, str + ")") : nullptr;
        }
    };

    vector<string> generateParenthesis(int n)
    {
        vector<Node *> nodes = {new Node(0, 0, n, "")};
        vector<Node *> new_nodes = {};

        for (int i = 0; i < 2 * n; i++)
        {
            for (int j = 0; j < nodes.size(); j++)
            {
                nodes[j]->Grow();

                if (nodes[j]->left != nullptr)
                    new_nodes.push_back(nodes[j]->left);
                if (nodes[j]->right != nullptr)
                    new_nodes.push_back(nodes[j]->right);
            }

            nodes = new_nodes;
            new_nodes.clear();
        }

        vector<string> res;
        for (int i = 0; i < nodes.size(); i++)
        {
            res.push_back(nodes[i]->str);
        }

        return res;
    }
};