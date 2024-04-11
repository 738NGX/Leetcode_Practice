#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    struct Node
    {
        int id;
        int val;
        Node *parent;
        Node(int id, int val) : id(id), val(val), parent(nullptr) {}
    };

    void dfs(vector<Node *> &nodes, vector<vector<int>> &adj, int curr, int parent)
    {
        for (int child : adj[curr])
        {
            if (child == parent)
                continue;
            nodes[child]->parent = nodes[curr];
            dfs(nodes, adj, child, curr);
        }
    }

    vector<int> getCoprimes(vector<int> &nums, vector<vector<int>> &edges)
    {
        vector<Node *> nodes;
        for (int i = 0; i < nums.size(); i++)
        {
            nodes.push_back(new Node(i, nums[i]));
        }

        vector<vector<int>> adj(nums.size());
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfs(nodes, adj, 0, -1);

        for (int i = 0; i < nodes.size(); i++)
        {
            auto ptr = nodes[i]->parent;
            int val = nodes[i]->val;
            while (ptr && __gcd(val, ptr->val) != 1)
            {
                ptr = ptr->parent;
            }
            if (ptr)
                nums[i] = ptr->id;
            else
                nums[i] = -1;
        }

        for (auto node : nodes)
            delete node;

        return nums;
    }
};
