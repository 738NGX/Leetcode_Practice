struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* result=new ListNode;
        ListNode *ptr=result,*ptr1=l1,*ptr2=l2;
        int advance=0;
        while(ptr1!=nullptr&&ptr2!=nullptr)
        {
            ListNode* next=new ListNode;
            ptr->next=next;
            ptr=ptr->next;
            int add=ptr1->val+ptr2->val+advance;
            advance=add/10;
            if(add>=10) add-=10;
            ptr->val=add;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        while(ptr1!=nullptr)
        {
            ListNode* next=new ListNode;
            ptr->next=next;
            ptr=ptr->next;
            int add=ptr1->val+advance;
            advance=add/10;
            if(add>=10) add-=10;
            ptr->val=add;
            ptr1=ptr1->next;
        }
        while(ptr2!=nullptr)
        {
            ListNode* next=new ListNode;
            ptr->next=next;
            ptr=ptr->next;
            int add=ptr2->val+advance;
            advance=add/10;
            if(add>=10) add-=10;
            ptr->val=add;
            ptr2=ptr2->next;
        }
        if(advance)
        {
            ListNode* next=new ListNode;
            ptr->next=next;
            ptr=ptr->next;
            ptr->val=advance;
        }
        ListNode* res=result->next;
        delete result;
        return res;
    }
};