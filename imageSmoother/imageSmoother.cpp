#include <vector>


class Solution
{
public:
    std::vector<std::vector<int>> imageSmoother(std::vector<std::vector<int>> &M)
    {
        if(M.empty() || M[0].empty()) return {};
        int m = M.size(), n = M[0].size();
        std::vector<std::vector<int>> res = M, dirs{{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                int cnt = M[i][j], all = 1;
                for(auto dir : dirs)
                {
                    int x = i + dir[0], y = j + dir[1];
                    if(x < 0 || x >= m || y < 0 || y >= n)
                        continue;
                    ++all;
                    cnt += M[x][y];
                }

                res[i][j] = cnt / all;
            }
        }

        return res;
    }
};
