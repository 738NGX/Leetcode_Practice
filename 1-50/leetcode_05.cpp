#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        string max = "";
        for (int i = 0; i < s.size() - 1; i++)
        {
            int j = s.size() - 1;
            while (i < j)
            {
                if (s[j] == s[i])
                {
                    bool is_palindrome;
                    string s_sub=s.substr(i, j - i + 1);
                    if (s_sub.size() < 2)
                        is_palindrome=true;
                    else
                    {
                        int l = 0, r = s_sub.size() - 1;
                        while (l < r)
                        {
                            if (s_sub[l] != s_sub[r])
                                break;
                            l++;
                            r--;
                        }
                        is_palindrome=s_sub[l] == s_sub[r];
                    }
                    
                    if (is_palindrome)
                    {
                        max = max.size() < j - i + 1 ? s.substr(i, j - i + 1) : max;
                        break;
                    }
                }
                j--;
            }
        }
        if (max == "" && s.size() > 0)
            max += s[0];
        return max;
    }
};

int main()
{
    Solution s;
    cout << s.longestPalindrome("babad");
    return 0;
}