#include <algorith>
#include <vector>

#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
    int numWays(int steps, int arrLen)
    {
        return dfs(steps, 0, arrLen);
    }

    int dfs(int steps, int pos, int arrLen)
    {
        if (pos >= arrLen || pos < 0 || steps < pos) return 0;
        if (steps == pos) return 1;

        int stay = dfs(steps - 1, pos, arrLen);
        int left = dfs(steps - 1, pos - 1, arrLen);
        int right = dfs(steps - 1, pos + 1, arrLen);

        return stay + left + right;
    }
#endif

#if method2
    int numWays(int steps, int arrLen)
    {
        int dp[2][253] = {0, 1};

        for (int i = 1; i <= steps; ++i)
        {
            for (int j = 1; j <= arrLen && j <= steps / 2 + 1; ++j)
            {
                dp[i&1][j] = ((dp[i&1^1][j-1] + dp[i&1^1][j]) % (1000000007) + dp[i&1^1][j+1]) % (1000000007);
            }
        }

        return dp[steps&1][1];
    }
#endif

#if method3
    int numWays(int steps, int arrLen)
    {
        int n = std::min(steps / 2 + 1, arrLen);
        std::vector<int> dp(n + 2), temp(n + 2);
        dp[1] = 1;

        for (int i = 0; i < steps; ++i)
        {
            std::swap(dp, temp);
            for (int j = std::min(n, i + 2);j; --j)
            {
                dp[j] = (temp[j - 1] + temp[j] + temp[j + 1]) % 1000000007;
            }
        }

        return dp[1];
    }
#endif
};
