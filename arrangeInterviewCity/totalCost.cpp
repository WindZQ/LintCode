#include <algorithm>
#include <vector>

class Solution
{
public:
    int totalCost(std::vector<std::vector<int>> &cost)
    {
        std::sort(cost.begin(), cost.end(), [](std::vector<int> first, std::vector<int>second) -> bool
        {
            return first[1] - first[0] < second[1] - second[0];
        });

        long long res = 0;
        int length = cost.size();
        int j = 0;

        for (auto i : cost)
        {
            if (2 * j < length)
            {
                res += i[1];
            }
            else
            {
                res += i[0];
            }

            ++j;
        }

        return res;
    }
};
