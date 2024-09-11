#include <iostream>

using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }

        long long a = labs(dividend), b = labs(divisor), res = 0;
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;

        while (a >= b)
        {
            long long temp = b, multiple = 1;
            while (a >= (temp << 1))
            {
                temp <<= 1;
                multiple <<= 1;
            }
            a -= temp;
            res += multiple;
        }

        return sign * res;
    }
};