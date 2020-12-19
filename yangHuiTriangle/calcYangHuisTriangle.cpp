#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> calcYangHuisTriangle(int n)
    {
        std::vector<std::vector<int>> res;
        if(n == 0) return res;

        for(int i = 0; i < n; ++i)
        {
            std::vector<int> tmp;
            tmp.push_back(1);
            for(int j = 1; j < i; ++j)
            {
                tmp.push_back(res[i - 1][j - 1] + res[i - 1][j]);
            }

            if(i > 0) tmp.push_back(1);

            res.push_back(tmp);
        }

        return res;
    }
};
