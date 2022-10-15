#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> highpoints(std::vector<std::vector<int>> &grid)
    {
        std::vector<std::vector<int>> out(grid.size(), std::vector<int>(grid[0].size()));
        auto exists = [&](int a, int b)
        {
            return a >= 0 && a < grid.size() && b >= 0 && b < grid[0].size();
        };

        auto add1 = [&](int a, int b)
        {
            if (exists(a, b))
                ++out[a][b];
            return 0;
        };

        auto compare = [&](int a, int b, int a2, int b2)
        {
            if (!exists(a, b)) return add1(a2, b2);
            if (!exists(a2, b2)) return add1(a, b);
            if (grid[a][b] == grid[a2][b2]) return 0;
            return grid[a][b] > grid[a2][b2] ? add1(a, b) : add1(a2, b2);
        };

        for (int i = -1; i <= (int)grid.size(); ++i)
        {
            for (int j = -1; j <= (int)grid[0].size(); ++j)
            {
                compare(i, j, i - 1, j);
                compare(i, j, i, j - 1);
                compare(i, j, i - 1, j - 1);
                compare(i, j, i + 1, j - 1);
            }
        }
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                out[i][j] /= 8;
            }
        }

        return out;
    }
};
