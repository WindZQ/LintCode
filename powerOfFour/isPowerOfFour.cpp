#include <math>

#define method1 1
#define method2 0
#define method3 0
#define method4 0


class Solution
{
public:
#if method1
    bool isPowerOfFour(int num)
    {
        while(num && (num % 4 == 0))
        {
            num /= 4;
        }

        return num == 1;
    }
#endif

#if method2
    bool isPowerOfFour(int num)
    {
        return num > 0 && int(log10(num) / log10(4)) - log10(num) / log10(4) == 0;
    }
#endif

#if method3
    bool isPowerOfFour(int num)
    {
        return num > 0 && !(num & (num - 1)) && (num - 1) % 3 == 0;
    }
#endif

#if method4
    bool isPowerOfFour(int num)
    {
        return num > 0 && !(num & (num - 1)) && (num & 0x55555555) == num;
    }
#endif
};
