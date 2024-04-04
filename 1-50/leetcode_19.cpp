#include <iostream>

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        auto dummy = new ListNode(0, head);
        auto ptr_a = dummy, ptr_b = dummy;

        for (int i = 0; i < n + 1; i++)
            ptr_a = ptr_a->next;

        while (ptr_a != nullptr)
        {
            ptr_a = ptr_a->next;
            ptr_b = ptr_b->next;
        }

        auto wait_delete = ptr_b->next;
        ptr_b->next = ptr_b->next->next;
        head = dummy->next;

        delete wait_delete;
        delete dummy;

        return head;
    }
};