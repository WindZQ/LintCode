#include <vector>
#include <queue>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    std::vector<std::vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int maxAreaOfIsland(std::vector<std::vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), res = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] != 1) continue;
                int cnt = 0;
                helper(grid, i, j, cnt, res);
            }
        }

        return res;
    }

    void helper(std::vector<std::vector<int>> &grid, int i, int j, int &cnt, int &res)
    {
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] <= 0) return;

        res = std::max(res, ++cnt);
        grid[i][j] *= -1;
        for(auto dir : dirs)
        {
            helper(grid, i + dir[0], j + dir[1], cnt, res);
        }
    }
#endif

#if method2
    std::vector<std::vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int maxAreaOfIsland(std::vector<std::vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), res = 0;

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] != 1) continue;
                int cnt = 0;
                std::queue<std::pair<int, int>> q{{{i, j}}};
                grid[i][j] *= -1;

                while(!q.empty())
                {
                    auto t = q.front();
                    q.pop();
                    res = std::max(res, ++cnt);

                    for(auto dir : dirs)
                    {
                        int x = t.first + dir[0], y = t.second + dir[1];
                        if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] <= 0) continue;
                        grid[x][y] *= -1;
                        q.push({x, y});
                    }
                }
            }
        }

        return res;
    }
#endif
};
