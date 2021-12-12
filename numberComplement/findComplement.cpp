#define method1 1
#define method2 0
#define method3 0


class Solution
{
public:
#if method1
    int findComplement(int num)
    {
        bool start = false;
        for(int i = 31; i >= 0; --i)
        {
            if(num & (1 << i)) start = true;
            if(start) num ^= (1 << i);
        }

        return num;
    }
#endif

#if method2
    int findComplement(int num)
    {
        int mask = INT_MAX;
        while(mask & num) mask <<= 1;
        return ~mask & ~num;
    }
#endif

#if method3
    int findComplement(int num)
    {
        return (1 - num % 2) + 2 * (num <= 1 ? 0 : findComplement(num / 2));
    }
#endif
};
