#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        return isMatchRecursive(s, 0, p, 0);
    }

private:
    bool isMatchRecursive(const string &s, int i, const string &p, int j)
    {
        if (j == p.size())
            return i == s.size();

        bool nextCharIsStar = (j + 1 < p.size() && p[j + 1] == '*');

        if (nextCharIsStar)
        {
            if (isMatchRecursive(s, i, p, j + 2))
                return true;
            if (i < s.size() && (s[i] == p[j] || p[j] == '.') && isMatchRecursive(s, i + 1, p, j))
                return true;
        }
        else
        {
            if (i < s.size() && (s[i] == p[j] || p[j] == '.'))
                return isMatchRecursive(s, i + 1, p, j + 1);
        }

        return false;
    }
};
