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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        bool init = true;
        auto l = head, r = head->next, last = head;

        while (l != nullptr && r != nullptr)
        {
            if (init)
            {
                head = r;
                init = false;
            }
            else
            {
                l = l->next;
                r = r->next;
                ListNode *t = l;
                l = r;
                r = t;
                if (r == nullptr)
                    break;
                last->next = r;
            }
            l->next = r->next;
            r->next = l;
            last = l;
            l = l->next;
            r = r->next;
        }

        return head;
    }
};