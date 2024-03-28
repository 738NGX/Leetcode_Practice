#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    std::pair<int, ListNode *> compareNodes(vector<ListNode *> &nodes)
    {
        if (nodes.size() == 0)
            return std::make_pair(0, nullptr);
        auto res = nodes[0];
        int min_val = INT_MAX;
        int res_idx = 0;
        for (int i = 0; i < nodes.size(); i++)
        {
            if (nodes[i] == nullptr)
                continue;
            if (nodes[i]->val < min_val)
            {
                min_val = nodes[i]->val;
                res = nodes[i];
                res_idx = i;
            }
        }
        return std::make_pair(res_idx, res);
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        auto compare_res = compareNodes(lists);

        auto start = compare_res.second, ptr = start;
        if (start == nullptr)
            return nullptr;

        lists[compare_res.first] = lists[compare_res.first]->next;

        while (true)
        {
            auto compare_res = compareNodes(lists);
            if (compare_res.second == nullptr)
                break;
            ptr->next = compare_res.second;
            ptr = ptr->next;
            lists[compare_res.first] = lists[compare_res.first]->next;
        }

        return compare_res.second;
    }
};