#include <algorithm>


class Solution
{
public:
    int groupBuyTimes(int x, int y, int z)
    {
        int result1 = (x + y + z) / 3;
        int result2 = std::min(x, y);

        return std::min(result1, result2);
    }
};
