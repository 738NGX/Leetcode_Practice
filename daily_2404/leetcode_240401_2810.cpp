#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string finalString(string &s)
    {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='i')
            {
                reverse(s.begin(),s.begin()+i);
            }
        }
        string res="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='i')
            {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};