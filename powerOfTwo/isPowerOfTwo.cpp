#define method1 1
#define method2 0
#define method3 0


class Solution
{
public:
#if method1
    bool isPowerOfTwo(int n)
    {
        for(int i = 0; i < 31; ++i)
        {
            if(n == 1 << i) return true;
        }

        return false;
    }
#endif

#if method2
    bool isPowerOfTwo(int n)
    {
        int res = 0;
        while(n > 0)
        {
            res += (n & 1);
            n >>= 1;
        }

        return res == 1;
    }
#endif

#if method3
    bool isPowerOfTwo(int n)
    {
        return (n > 0) && (!(n & (n - 1)));
    }
#endif
};
