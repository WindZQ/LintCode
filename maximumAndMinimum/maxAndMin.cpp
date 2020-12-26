#include <vector>
#include <math>

class Solution
{
public:
    std::vector<int> maxAndMin(std::vector<std::vector<int>> &matrix)
    {
        if(matrix.empty() || matrix[0].empty()) return {};
        std::vector<int> res = {INT_MIN, INT_MAX};

        for(int i = 0; i < matrix.size(); ++i)
        {
            for(int j = 0; j < matrix[0].size(); ++j)
            {
                res[0] = std::max(res[0], matrix[i][j]);
                res[1] = std::min(res[1], matrix[i][j]);
            }
        }

        return res;
    }
};
