#include <iostream>

#define method1 1
#define method2 0
#define method3 0


class Solution
{
public:
#if method1
    int reverseInteger(int n)
    {
        int res = 0;
        while(n != 0)
        {
            int next_res = res * 10 + n % 10;
            n /= 10;
            if(next_res / 10 != res)
            {
                res = 0;
                break;
            }
            res = next_res;
        }
        return res;
    }
#endif

#if method2
    int reverseInteger(int n)
    {
        int res = 0;
        while(n != 0)
        {
            if(abs(n) > INT_MAX % 10) return 0;
            res = res * 10 + n / 10;
            n /= 10;
        }
        return res;
    }
#endif

#if method3
    int  reverseInteger(int n)
    {
        long res = 0;
        while(n != 0)
        {
            res = 10 * res + n % 10;
            n /= 10;
        }
        return (res > INT_MAX || res < INT_MIN) ? 0 : res;
    }
#endif
}
