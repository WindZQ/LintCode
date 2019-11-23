#include <iostream>
#include <vector>
#include <limits.h>

#define method1 0
#define method2 0
#define method3 0
#define method4 1


class Solution
{
public:
#if method1
    int minPathSum(std::vector<std::vector<int>> &grid)
    {
        if(grid.empty() || grid[0].empty())
        {
            return 0;
        }
        int m = grid.size(), n = grid[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < m; ++i)
        {
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        }
        for(int j = 1; j < n; ++j)
        {
            dp[0][j] = grid[0][j] + dp[0][j - 1];
        }

        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                dp[i][j] = grid[i][j] + std::min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m - 1][n - 1];
    }
#endif

#if method2
    int minPathSum(std::vector<std::vector<int>> &grid)
    {
        if(grid.empty() || grid[0].empty())
        {
            return 0;
        }
        int m = grid.size(), n = grid[0].size();
        std::vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(j == 0)
                {
                    dp[j] += grid[i][j];
                }
                else
                {
                    dp[j] = grid[i][j] + std::min(dp[j], dp[j - 1]);
                }
            }
        }
        return dp[n - 1];
    }
#endif

#if method3
    int minPathSum(std::vector<std::vector<int>> &grid)
    {
        if(grid.empty() || grid[0].empty())
        {
            return 0;
        }
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[i].size(); ++j)
            {
                if(i == 0 && j == 0)
                {
                    continue;
                }

                if(i == 0)
                {
                    grid[0][j] += grid[0][j - 1];
                }
                else if(j == 0)
                {
                    grid[i][0] += grid[i - 1][0];
                }
                else
                {
                    grid[i][j] += std::min(grid[i - 1][j], grid[i][j - 1]);
                }
            }
        }
        return grid.back().back();
    }
#endif

#if method4
    int minPathSum(std::vector<std::vector<int>> &grid)
    {
        if(grid.empty() || grid[0].empty())
        {
            return 0;
        }

        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[i].size(); ++j)
            {
                if(i == 0 && j == 0)
                {
                    continue;
                }

                int up = (i == 0) ? INT_MAX : grid[i - 1][j];
                int left = (j == 0) ? INT_MAX : grid[i][j - 1];
                grid[i][j] += std::min(up, left);
            }
        }
        return grid.back().back();
    }
#endif
};

int main(void)
{
    int a[6][2] = {{7, 2}, {6, 6}, {8, 6}, {8, 7}, {5, 0}, {6, 0}};
    Solution s;
    std::vector< std::vector<int> > grid;
    for(int i = 0; i < 6; i++)
    {
        std::vector<int> v;
        for(int j = 0; j < 2; j++)
        {
            v.push_back(a[i][j]);
        }
        grid.push_back(v);
    }

    std::cout << "minPathSum = " << s.minPathSum(grid) << std::endl;

    return 0;
}
