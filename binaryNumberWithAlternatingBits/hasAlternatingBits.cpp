#define method1 1
#define method2 0
#define method3 0
#define method4 0


class Solution
{
public:
#if method1
    bool hasAlternatingBits(int n)
    {
        int bits = -1;
        while(n > 0)
        {
            if(n & 1 == 1)
            {
                if(bits == 1) return false;
                bits = 1;
            }
            else
            {
                if(bits == 0) return false;
                bits = 0;
            }
            n >>= 1;
        }

        return true;
    }
#endif

#if method2
    bool hasAlternatingBits(int n)
    {
        int d = n & 1;
        while((n & 1) == d)
        {
            d ^= 1;
            n >>= 1;
        }

        return n == 0;
    }
#endif

#if method3
    bool hasAlternatingBits(int n)
    {
        return ((n + (n >> 1) + 1) & (n + (n >> 1))) == 0;
    }
#endif

#if method4
    bool hasAlternatingBits(int n)
    {
        return ((n ^= n / 4) & (n - 1)) == 0;
    }
#endif
};
