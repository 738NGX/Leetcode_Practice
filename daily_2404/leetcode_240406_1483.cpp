#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class TreeAncestor
{
public:
    struct Node
    {
        int id;
        Node *parent;
        Node(int id) : id(id), parent(nullptr) {}
        Node(int id, Node *parent) : id(id), parent(parent) {}
    };

    std::vector<Node *> nodes;
    std::vector<std::vector<int>> up;
    int LOG;

    void giveParent(std::vector<Node *> &nodes, int c, int p, std::vector<int> parent)
    {
        if (p == -1)
        {
            nodes[c] = new Node(c);
            return;
        }
        if (!nodes[p])
            giveParent(nodes, p, parent[p], parent);
        nodes[c] = new Node(c, nodes[p]);
    }

    TreeAncestor(int n, const std::vector<int> &parent)
    {
        nodes = std::vector<Node *>(n, nullptr);
        LOG = std::log2(n) + 1;
        up = std::vector<std::vector<int>>(n, std::vector<int>(LOG, -1));
        for (int i = 0; i < n; i++)
        {
            if (!nodes[i])
                giveParent(nodes, i, parent[i], parent);
            if (nodes[i]->parent != nullptr)
                up[i][0] = nodes[i]->parent->id;
        }

        for (int j = 1; j < LOG; ++j)
        {
            for (int i = 0; i < n; ++i)
            {
                int intermediate = up[i][j - 1];
                if (intermediate != -1)
                {
                    up[i][j] = up[intermediate][j - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k)
    {
        for (int j = 0; j < LOG; ++j)
        {
            if (k & (1 << j))
            {
                node = up[node][j];
                if (node == -1)
                    return -1;
            }
        }
        return node;
    }
};

int main()
{
    TreeAncestor t(7, {-1, 0, 0, 1, 1, 2, 2});
    cout << t.getKthAncestor(3, 1) << endl;
    cout << t.getKthAncestor(5, 2) << endl;
    cout << t.getKthAncestor(6, 3) << endl;
    return 0;
}