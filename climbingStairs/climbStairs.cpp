#include <iostream>
#include <vector>

#define method1 0
#define method2 0
#define method3 1

class Solution
{
public:
#if method1
    int climbStairs(int n)
    {
        if(n < 4) return n;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
#endif

#if method2
    int climbStairs(int n)
    {
        if(n == 0) return 0;
        std::vector<int> res(3);
        res[0] = 1;
        res[1] = 1;

        for(int i = 2; i <= n; ++i)
            res[i % 3] = res[(i - 1) % 3] + res[(i - 2) % 3];
        return res[n % 3];
    }
#endif

#if  method3
    int climbStairs(int n)
    {
        if(n < 4) return n;
        int a = 2, b = 3, c = 5;

        for(int i = 5; i <= n; ++i)
        {
            a = c;
            c += b;
            b = a;
        }
        return c;
    }
#endif
};

int main(void)
{
    int n = 0, m = 0;
    Solution s;
    printf("Please input the number:");
    scanf("%d", &n);
    printf("The reslut is %d\n", s.climbStairs(n));
    return 0;
}
