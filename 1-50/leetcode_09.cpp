#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) 
    {
        string s=to_string(x);
        return isPalindromeRec(s);
    }
    bool isPalindromeRec(string s)
    {
        if(s.size()<=1) return true;
        if(s[0]!=s[s.size()-1]) return false;
        else return isPalindromeRec(s.substr(1,s.size()-2));
    }
};