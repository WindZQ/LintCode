#include <vector>

class Solution
{
public:
    int matrixGame(std::vector<std::vector<int> &grids)
    {
        if (grids.size() == 0 || grids[0].size() == 0) return 0;

        std::vector<int> v(grids[0].size());

        for (int j = 0; j < grids[0].size(); ++j)
        {
            int max_number = 0;

            for (int i = 0; i < grids.size(); ++i)
            {
                max_number = std::max(max_number, grids[i][j]);
            }

            v[j] = max_number;
        }

        int first = 0, second = 0;
        std::sort(v.begin(), v.end());

        for (int i = 0; i < v.size(); ++i)
        {
            if (i % 2 == 0)
            {
                first += v[i];
            }
            else
            {
                second += v[i];
            }
        }

        return std::abs(first - second);
    }
};
