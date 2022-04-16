#define method1 1
#define method2 0
#define method3 0


class Solution
{
public:
#if method1
    int trailingZeroes(int n)
    {
        int res = 0;
        for(int i = 5; i <= n; i += 5)
        {
            for(int x = i; x % 5 == 0; x /= 5)
            {
                res++;
            }
        }

        return res;
    }
#endif

#if method2
    int trailingZeroes(int n)
    {
        int res = 0;
        while(n)
        {
            n /= 5;
            res += n;
        }

        return res;
    }
#endif

#if method3
    int trailingZeroes(int n)
    {
        return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
#endif
};
