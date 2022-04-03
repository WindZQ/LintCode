#define method1 1
#define method2 0
#define method3 0
#define method4 0
#define method5 0
#define method6 0

class Solution
{
public:
#if method1
    long long reverseBits(long long n)
    {
        long long res = 0;
        for(int i = 0; i < 32; ++i)
        {
            if(n & 1 == 1)
            {
                res = (res << 1) + 1;
            }
            else
            {
                res = res << 1;
            }

            n = n >> 1;
        }

        return res;
    }
#endif

#if method2
    long long reverseBits(long long n)
    {
        long long res = 0;
        for(int i = 0; i < 32; ++i)
        {
            res <<= 1;
            if((n & 1) == 1) ++res;
            n >>= 1;
        }

        return res;
    }
#endif

#if method3
    long long reverseBits(long long n)
    {
        long long res = 0;
        for(int i = 0; i < 32; ++i)
        {
            res = (res << 1) | (n & 1);
            n >>= 1;
        }

        return res;
    }
#endif

#if method4
    long long reverseBits(long long n)
    {
        long long res = 0;
        for(int i = 0; i < 32; ++i)
        {
            res = (res << 1) + (n >> i & 1);
        }

        return res;
    }
#endif

#if method5
    long long reverseBits(long long n)
    {
        long long res = 0;
        for(int i = 0; i < 32; ++i)
        {
            res |= ((n >> i) & 1) << (31 - i);
        }

        return res;
    }
#endif

#if method6
    long long reverseBits(long long n)
    {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
#endif
};
