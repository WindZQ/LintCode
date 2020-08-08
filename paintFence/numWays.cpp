#include <vector>
#include <pair>

#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
    int numWays(int n, int k)
    {
        std::vector<int> dp = {0, k, k * k, 0};
        if(n <= 2) return dp[n];
        if(k == 1) return 0;
        for(int i = 3; i <= n; ++i)
        {
            dp[3] = (k - 1) * (dp[1] + dp[2]);
            dp[1] = dp[2];
            dp[2] = dp[3];
        }

        return dp[3];
    }
#endif

#if method2
    int numWays(int n, int k)
    {
        std::vector<pair<int, int>> f(n + 1, {0, 0});
        f[1].first = k;
        f[1].second = 0;
        f[2].first = k * (k - 1);
        f[2].second = k;
        for(int i = 3; i <= n; ++i)
        {
            f[i].first = (f[i - 1].first + f[i - 1].second) * (k - 1);
            f[i].second = f[i - 1].first;
        }
        return f[n].first + f[n].second;
    }
#endif

#if method3
    int numWays(int n, int k)
    {
        if(n == 0) return 0;
        int same = 0, diff = k;
        for(int i = 2; i <= n; ++i)
        {
            int t = diff;
            diff = (same + diff) * (k - 1);
            same = t;
        }

        return same + diff;
    }
#endif
};
