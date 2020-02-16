#include <iostream>


#define method1 0
#define method2 0
#define method3 1

class Solution
{
public:
#if method1
    int bitSwapRequired(int a, int b)
    {
        int swaps = 0;
        for(int i = 0; i < 32; ++i)
        {
            if((a &(1 << i)) != (b &(1 << i)))
            {
                swaps++;
            }
        }
        return swaps;
    }
#endif

#if method2
    int bitSwapRequired(int a, int b)
    {
        int swaps = 0;
        int num = a ^ b;

        for(int i = 0; i < 32; ++i)
        {
            if(num & (1 << i))
            {
                swaps++;
            }
        }
        return swaps;
    }
#endif

#if method3
    int bitSwapRequired(int a, int b)
    {
        int count = 0;
        for(unsigned int c = a ^ b; c != 0; c >>= 1)
        {
            count += c & 1;
        }
        return count;
    }
#endif
};

int main(void)
{
    Solution s;
    int a = 14, b = 31;
    int result = 0;

    result = s.bitSwapRequired(a, b);
    std::cout << result << std::endl;

    return 0;
}
