#include <iostream>
#include <vector>

#define method1 0
#define method2 0
#define method3 1


class Solution
{
public:
#if method1
    int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        if(m <= 0)
        {
            return 0;
        }
        int n = obstacleGrid[0].size();
        if(n <= 0)
        {
            return 0;
        }

        if(obstacleGrid[0][0] == 1)
        {
            return 0;
        }

        int map[101][101];
        map[0][0] = 1;
        for(int i = 1; i < m; ++i)
        {
            if(obstacleGrid[i][0] == 1)
            {
                map[i][0] = 0;
            }
            else
            {
                map[i][0] = map[i - 1][0];
            }
        }

        for(int i = 1; i < n; ++i)
        {
            if(obstacleGrid[0][i] == 1)
            {
                map[0][i] = 0;
            }
            else
            {
                map[0][i] = map[0][i - 1];
            }
        }

        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                if(obstacleGrid[i][j] == 1)
                {
                    map[i][j] = 0;
                }
                else
                {
                    map[i][j] = map[i - 1][j] + map[i][j- 1];
                }
            }
        }
        return map[m - 1][n - 1];
    }
#endif

#if method2
    int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid)
    {
        if(obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1)
            return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        std::vector<std::vector<long>> dp(m + 1, std::vector<long>(n + 1, 0));
        dp[0][1] = 1;

        for(int i = 1; i <= m; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(obstacleGrid[i - 1][j - 1] != 0)
                {
                    continue;
                }
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
#endif

#if method3
    int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid)
    {
        if(obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1)
        {
            return 0;
        }

        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        std::vector<long> dp(n, 0);
        dp[0] = 1;

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(obstacleGrid[i][j] == 1)
                {
                    dp[j] = 0;
                }
                else if(j > 0)
                {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp[n - 1];
    }
#endif
};

int main(void)
{
    Solution s;
    std::vector<std::vector<int>> v{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    std::cout << s.uniquePathsWithObstacles(v) << std::endl;
    return 0;
}
