#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution
{
public:
    class Node
    {
    public:
        int id;
        vector<Node *> last;
        Node(int id) : id(id), last({}) {}
        
    };

    set<int> get_ancestors(Node* n,map<int,set<int>> &ancestors_map)
    {
        if(ancestors_map.find(n->id)!=ancestors_map.end())
        {
            return ancestors_map[n->id];
        }
        set<int> result;
        for (auto node : n->last)
        {
            result.insert(node->id);
            if(node->last.size()==0) continue;
            auto node_ancesters = get_ancestors(node,ancestors_map);
            result.insert(node_ancesters.begin(),node_ancesters.end());
        }
        ancestors_map[n->id]=result;
        return result;
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        vector<Node *> nodes;
        map<int,set<int>> ancestors_map;
        for (int i = 0; i < n; i++)
        {
            nodes.push_back(new Node(i));
        }
        for (auto edge : edges)
        {
            nodes[edge[1]]->last.push_back(nodes[edge[0]]);
        }
        vector<vector<int>> result;
        for (auto node : nodes)
        {
            auto get_set=get_ancestors(node,ancestors_map);
            result.push_back(vector<int>(get_set.begin(),get_set.end()));
        }
        return result;
    }
};