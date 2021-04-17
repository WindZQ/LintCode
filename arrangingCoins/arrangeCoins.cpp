#include <math>

#define method1 1
#define method2 0
#define method3 0


class Solution
{
public:
#if method1
    int arrangeCoins(int n)
    {
        int cur = 1, rem = n - 1;
        while(rem >= cur + 1)
        {
            ++cur;
            rem -= cur;
        }

        return n == 0 ? 0 : cur;
    }
#endif

#if method2
    int arrangeCoins(int n)
    {
        if(n <= 1) return n;
        long low = 1, high = n;

        while(low < high)
        {
            long mid = low + (high - low) / 2;
            if(mid * (mid + 1) / 2 <= n)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }

        return low - 1;
    }
#endif

#if method3
    int arrangeCoins(int n)
    {
        return (int)((-1 + std::sqrt(1 + 8 * (long)n)) / 2);
    }
#endif
};
