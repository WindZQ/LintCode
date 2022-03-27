#define method1 1
#define method2 0


class Solution
{
public:
#if method1
    int hammingWeight(int n)
    {
        int res = 0;

        for(int i = 0; i < 32; ++i)
        {
            if(n & (1 << i))
            {
                ++res;
            }
        }

        return res;
    }
#endif

#if method2
    int hammingWeight(int n)
    {
        int res = 0;

        while(n)
        {
            n &= n - 1;
            res++;
        }

        return res;
    }
#endif
};
