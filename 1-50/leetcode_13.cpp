#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
    int i;
    int x=0;
    for(i=0;i<=s.size();i++)
    {
        if((s[i]=='I'&&(s[i+1]=='V'||s[i+1]=='X'))||(s[i]=='X'&&(s[i+1]=='L'||s[i+1]=='C'))||(s[i]=='C'&&(s[i+1]=='D'||s[i+1]=='M')))
        {
            switch(s[i])
            {
                case 'I':
                    switch(s[i+1])
                    {
                        case 'V': x+=4; break;
                        case 'X': x+=9; break;
                    }
                    break;
                case 'X':
                    switch(s[i+1])
                    {
                        case 'L': x+=40; break;
                        case 'C': x+=90; break;
                    }
                    break;
                case 'C':
                    switch(s[i+1])
                    {
                        case 'D': x+=400; break;
                        case 'M': x+=900; break;
                    }
                    break;
            }
            i++;
        }
        else
        {
            switch(s[i])
            {
                case 'I': x+=1; break;
                case 'V': x+=5; break;
                case 'X': x+=10; break;
                case 'L': x+=50; break;
                case 'C': x+=100; break;
                case 'D': x+=500; break;
                case 'M': x+=1000; break;
            }
        }
    }
    return(x);
    }
};