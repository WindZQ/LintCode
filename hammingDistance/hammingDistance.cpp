#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
    int hammingDistance(int x, int y)
    {
        int res = 0;

        while(x != 0 || y != 0)
        {
            if(x % 2 != y % 2)
            {
                res++;
            }
            x /= 2;
            y /= 2;
        }

        return res;
    }
#endif

#if method2
    int hammingDistance(int x, int y)
    {
        int diff = x ^ y;
        size_t res = 0;
        while(diff)
        {
            ++res;
            diff &= diff - 1;
        }
        return res;
    }
#endif

#if method3
    int hammingDistance(int x, int y)
    {
        x ^= y;
        const uint64_t m1  = 0x5555555555555555;
        const uint64_t m2  = 0x3333333333333333;
        const uint64_t m4  = 0x0f0f0f0f0f0f0f0f;
        const uint64_t h01 = 0x0101010101010101;
        x -= (x >> 1) & m1;
        x = (x & m2) + ((x >> 2) & m2);
        x = (x + (x >> 4)) & m4;

        return (x * h01) >> 56;
    }
#endif

};
