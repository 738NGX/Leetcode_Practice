#include<iostream>

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
    ListNode* mergeTwoLists(ListNode* list1,ListNode* list2)
    {
        auto *ptr1=list1,*ptr2=list2;

        if(ptr1==nullptr&&ptr2==nullptr) return nullptr;
        if(ptr1!=nullptr&&ptr2==nullptr) return ptr1;
        if(ptr1==nullptr&&ptr2!=nullptr) return ptr2;
        
        auto *res=new ListNode(),*ptr=res;

        while(ptr1!=nullptr&&ptr2!=nullptr)
        {
            if(ptr1->val<=ptr2->val)
            {
                ptr->next=new ListNode(ptr1->val);
                ptr1=ptr1->next;
            }
            else
            {
                ptr->next=new ListNode(ptr2->val);
                ptr2=ptr2->next;
            }
            ptr=ptr->next;
        }
        if(ptr1!=nullptr) ptr->next=ptr1;
        if(ptr2!=nullptr) ptr->next=ptr2;

        return res->next;
    }
};