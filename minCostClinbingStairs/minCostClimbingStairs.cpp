#include <vector>
#include <unordered_map>

#define method1 1
#define method2 0
#define method3 0
#define method4 0


class Solution
{
public:
#if method1
    int minCostClimbingStairs(std::vector<int> &cost)
    {
        int a = 0, b = 0;
        for(int num : cost)
        {
            int t = std::min(a, b) + num;
            a = b;
            b = t;
        }

        return std::min(a, b);
    }
#endif

#if method2
    int minCostClimbingStairs(std::vector<int> &cost)
    {
        int n = cost.size();
        std::vector<int> dp(n + 1);
        for(int i = 2; i < n + 1; ++i)
        {
            dp[i] = std::min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
        }

        return dp.back();
    }
#endif

#if method3
    int minCostClimbingStairs(std::vector<int> &cost)
    {
        int n = cost.size();
        std::vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i < n; ++i)
        {
            dp[i] = cost[i] + std::min(dp[i - 1], dp[i - 2]);
        }

        return std::min(dp[n - 1], dp[n - 2]);
    }
#endif

#if method4
    int minCostClimbingStairs(std::vector<int> &cost)
    {
        std::unordered_map<int, int> memo;
        return helper(cost, cost.size(), memo);
    }

    int helper(std::vector<int> &cost, int n, std::unordered_map<int, int> &memo)
    {
        if(memo.count(n)) return memo[n];
        if(n <= 1) return memo[n] = cost[n];

        return memo[n] = (n == cost.size() ? 0 : cost[n]) + std::min(helper(cost, n - 1, memo), helper(cost, n - 2, memo));
    }
#endif
};
