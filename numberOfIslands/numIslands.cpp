#include <iostream>
#include <vector>
#include <queue>

#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
    void dfs(std::vector<std::vector<bool>> &grid, int i, int j)
    {
        int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
        int n = grid.size(), m = grid[0].size();

        for(int k = 0; k < 4; ++k)
        {
            int next_i = i + dir[k][0], next_j = j + dir[k][1];
            if(next_i >= 0 && next_i < n && next_j >= 0 && next_j < m && grid[next_i][next_j])
            {
                grid[next_i][next_j] = false;
                dfs(grid, next_i, next_j);
            }
        }
    }

    int numIslands(std::vector<std::vector<bool>> &grid)
    {
        if(grid.size() == 0) return 0;
        int n = grid.size(), m = grid[0].size();
        int ans = 0;

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(grid[i][j])
                {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }
#endif

#if method2
    void bfs(std::vector<std::vector<bool>> &grid, int i, int j)
    {
        std::pair<int, int> now(i, j);
        std::queue<std::pair<int, int>> q;
        int n = grid.size(), m = grid[0].size();
        int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
        q.push(now);

        while(!q.empty())
        {
            now = q.front();
            q.pop();

            for(int k = 0; k < 4; ++k)
            {
                std::pair<int, int> next(now.first + dir[k][0], now.second + dir[k][1]);
                if(next.first >= 0 && next.first < n && next.second >= 0 && next.second < m && grid[next.first][next.second])
                {
                    q.push(next);
                    grid[next.first][next.second] = 0;
                }
            }
        }
    }

    int numIslands(std::vector<std::vector<bool>> &grid)
    {
        if(grid.size() == 0) return 0;
        int n = grid.size(), m = grid[0].size();
        int ans = 0;

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(grid[i][j])
                {
                    bfs(grid, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }
#endif

#if method3
    int pre[100000];
    int ans = 0;

    int unionfind(int root)
    {
        int son, tmp;
        son = root;

        while(root != pre[root])
        {
            root = pre[root];
        }

        while(son != root)
        {
            tmp = pre[son];
            pre[son] = root;
            son = tmp;
        }

        return root;
    }

    void connect(int A, int B)
    {
        int rootA = unionfind(A);
        int rootB = unionfind(B);

        if(rootA != rootB)
        {
            pre[rootB] = rootA;
            ans--;
        }
    }

    int numIslands(std::vector<std::vector<bool>> &grid)
    {
        if(grid.size() == 0) return 0;
        int n = grid.size(), m = grid[0].size();
        std::map<pair<int, int>, int> index;

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(grid[i][j])
                {
                    std::pair<int, int> tmp(i, j);
                    pre[ans] = ans;
                    index[tmp] = ans++;
                }
            }
        }

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(grid[i][j])
                {
                    std::pair<int, int> now(i, j);
                    if(i + 1 < n && grid[i + 1][j])
                    {
                        std::pair<int, int> up(i + 1, j);
                        connect(index[up], index[now]);
                    }

                    if(j + 1 < m && grid[i][j + 1])
                    {
                        std::pair<int, int> left(i, j + 1);
                        connect(index[left], index[now]);
                    }
                }
            }
        }
        return ans;
    }
#endif
};
