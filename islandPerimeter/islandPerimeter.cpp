#include <vector>

#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
    int islandPerimeter(std::vector<std::vector<int>> &grid)
    {
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size(), res = 0;

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == 0) continue;
                if(j == 0 || grid[i][j - 1] == 0) ++res;
                if(i == 0 || grid[i - 1][j] == 0) ++res;
                if(j == n - 1 || grid[i][j + 1] == 0) ++res;
                if(i == m - 1 || grid[i + 1][j] == 0) ++res;
            }
        }

        return res;
    }
#endif

#if method2
    int islandPerimeter(std::vector<std::vector<int>> &grid)
    {
        if(grid.empty() || grid[0].empty()) return 0;
        int res = 0, m = grid.size(), n = grid[0].size();

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == 0) continue;
                res += 4;
                if(i > 0 && grid[i - 1][j] == 1) res -= 2;
                if(j > 0 && grid[i][j - 1] == 1) res -= 2;
            }
        }

        return res;
    }
#endif

#if method3
    constexpr static int dx[4] = {0, 1, 0, -1};
    constexpr static int dy[4] = {1, 0, -1, 0};

    int islandPerimeter(std::vector<std::vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        int res = 0;

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                res += dfs(i, j, grid, n, m);
            }
        }

        return res;
    }
#endif

    int dfs(int x, int y, std::vector<std::vector<int>> &grid, int n, int m)
    {
        if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0)
            return 1;

        if(grid[x][y] == 2) return 0;

        grid[x][y] = 2;
        int res = 0;

        for(int i = 0; i < 4; ++i)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            res += dfs(tx, ty, grid, n, m);
        }

        return res;
    }
};
