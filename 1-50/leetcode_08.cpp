#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) 
    {
        int result=0;
        bool positive=true;
        bool num_start=false;
        for(int i=0;i<s.size();i++)
        {
            if(!num_start)
            {
                switch (s[i])
                {
                    case '-': num_start=true; positive=false; break;
                    case '+': num_start=true; positive=true; break;
                    default: break;
                }
                if(s[i]<='9'&&s[i]>='0')
                {
                    num_start=true;
                    result+=s[i]-'0';
                }
                else if(s[i]!='-'&&s[i]!='+'&&s[i]!=' ') return 0;
            }
            else
            {
                if(s[i]>'9'||s[i]<'0') break;
                if(result>INT_MAX/10) return INT_MAX;
                else if(result==INT_MAX/10)
                {
                    if(s[i]-'0'>=INT_MAX%10) return INT_MAX;
                }
                else if(result<INT_MIN/10) return INT_MIN;
                else if(result==INT_MIN/10)
                {
                    if(s[i]-'0'>=8) return INT_MIN;
                }
                if(positive)
                    result=result*10+(s[i]-'0');
                else
                    result=result*10-(s[i]-'0');
            }
        }
        return result;
    }
};