#include <iostream>
#include <vector>

#define method1 0
#define method2 0
#define method3 1


class Solution
{
public:
    #if method1
    int uniquePaths(int m, int n)
    {
        std::vector<std::vector<int>> f(m, std::vector<int>(n));

        for(int i = 0; i < n; ++i)
            f[0][i] = 1;

        for(int i = 0; i < m; ++i)
            f[i][0] = 1;

        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }

        return f[m - 1][n - 1];
    }
    #endif

    #if method2
    int uniquePaths(int m, int n)
    {
        std::vector<int> dp(n, 1);

        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
    #endif

    #if method3
    int uniquePaths(int m, int n)
    {
        double num = 1, denom = 1;
        int small = m > n ? n : m;

        for(int i = 1; i <= small - 1; ++i)
        {
            num *= m + n - 1 - i;
            denom *= i;
        }
        return (int)(num / denom + 0.5);
    }
    #endif
};

int main(int argc, char **argv)
{
    Solution s;
    int m = 3, n = 7;

    if(argc > 2)
    {
        m = atoi(argv[1]);
        n = atoi(argv[2]);
    }

    printf("uniquePaths = %d\n", s.uniquePaths(m, n));
    return 0;
}
