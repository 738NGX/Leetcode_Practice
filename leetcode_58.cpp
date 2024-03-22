#include <iostream>
# include <string>

using namespace std;

class Solution 
{
public:
    int lengthOfLastWord(string s) 
    {
        bool start=false;
        int start_idx=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[s.size()-1-i]==' ')
            {
                if(!start) continue;
                return i-start_idx;
            }
            else
            {
                if(!start)
                {
                    start=true;
                    start_idx=i;
                }
            }
        }
        return s.size()-start_idx;
    }
};