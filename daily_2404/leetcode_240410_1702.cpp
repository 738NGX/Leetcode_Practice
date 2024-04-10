#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string maximumBinaryString(string &binary)
    {
        int n = binary.size();
        int j = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (binary[i] != '0')
                continue;

            if (binary[i + 1] == '0')
            {
                binary[i] = '1';
                continue;
            }

            j = max(i + 1, j);
            while (j < n && binary[j] != '0')
            {
                j++;
            }
            if (j == n)
                break;
            binary[i + 1] = '0';
            binary[j] = '1';
            binary[i] = '1';
        }
        return binary;
    }
};