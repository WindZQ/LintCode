#include <vector>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    std::vector<std::vector<int>> spiralArray(int n)
    {
        std::vector<std::vector<int>> res;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        for(int i = 0; i < n; ++i)
        {
            res.push_back(std::vector<int>());
            for(int j = 0; j < n; ++j)
            {
                res[i].push_back(-1);
            }
        }

        int x = 0, y = 0, d = 0;
        for(int i = 1; i <= n * n; ++i)
        {
            res[x][y] = i;
            int nx = x + dx[d];
            int ny = y + dy[d];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n || res[nx][ny] != -1)
            {
                d = (d + 1) % 4;
                nx = x + dx[d];
                ny = y + dy[d];
            }
            x = nx;
            y = ny;
        }
        return res;
    }
#endif

#if method2
    std::vector<int> dirs = {0, 1, 0, -1, 0};
    std::vector<std::vector<int>> spiralArray(int n)
    {
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
        dfs(matrix, 1, 0, 0, n);
        return matrix;
    }

    void dfs(std::vector<std::vector<int>> &matrix, int start, int x, int y, int n)
    {
        if(n == 0) return ;
        if(n == 1)
        {
            matrix[x][y] = start;
            return;
        }

        int xx = x;
        int yy = y;
        for(int k = 0; k < 4; ++k)
        {
            for(int num = 0; num < n - 1; ++num)
            {
                matrix[x][y] = start++;
                x += dirs[k];
                y += dirs[k + 1];
            }
        }
        dfs(matrix, start, xx + 1, yy + 1, n - 2);
    }
#endif
};
