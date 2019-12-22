#include <iostream>

#define method1 0
#define method2 0
#define method3 1

class Solution
{
public:
#if method1
    bool checkPowerOf2(int n)
    {
        if(n == 0)
        {
            return false;
        }
        while(n % 2 == 0)
        {
            n /= 2;
        }
        return n == 1;
    }
#endif

#if method2
    bool checkPowerOf2(int n)
    {
        int cnt = 0;
        while(n > 0)
        {
            cnt += (n & 1);
            n >>= 1;
        }
        return cnt == 1;
    }
#endif

#if method3
    bool checkPowerOf2(int n)
    {
        return (n > 0) && (!(n & (n - 1)));
    }
#endif
};

int main(void)
{
    Solution s;
    int n = 0;
    bool result;
    printf("Please input the number:");
    scanf("%d", &n);
    result = s.checkPowerOf2(n);
    if(result)
    {
        printf("True!\n");
    }
    else
    {
        printf("False!\n");
    }
    return 0;
}
