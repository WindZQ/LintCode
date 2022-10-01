#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    int fibonacci(int n)
    {
        int f[n - 1];
        f[0] = 0;
        f[1] = 1;

        for (int i = 2; i <= n; ++i)
        {
            f[i] = f[i - 1] + f[i - 2];
        }

        return f[n - 1];
    }
#endif

#if method2
    int fibonacci(int n)
    {
        int dp[n - 1];
        dp[0] = 0;
        dp[1] = 1;

        if (n <= 1)
        {
            return dp[n];
        }
        else
        {
            for (int i = 2; i < n; ++i)
            {
                dp[i] = dp[i - 1] + dp[i -2];
            }

            return dp[n - 1];
        }
    }
#endif
};
