#include<iostream>

using namespace std;

class Solution 
{
public:
    struct Node
    {
        int val;
        Node* next;
        Node(){val=0; next=nullptr;}
        Node(int n)
        {
            int abs_n=n<0?-n:n;
            val=abs_n%10; 
            next=nullptr;
            if(abs_n/10!=0)
            {
                Node* nextNode=new Node(abs_n/10);
                next=nextNode;
            }
        }
    };
    
    int reverse(int x) 
    {
        if(x>INT_MAX||x<=INT_MIN) return 0;
        int abs_x=x<0 ? -x : x;
        Node* start=new Node(abs_x);
        Node* ptr=start;
        long long result=0;
        while(ptr!=nullptr)
        {
            result=result*10+ptr->val;
            Node* next=ptr->next;
            delete ptr;
            ptr=next;
        }
        if(result>INT_MAX||result<INT_MIN) return 0;
        return x<0 ? -result : result;
    }
};