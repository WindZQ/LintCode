#include <vector>
#include <algorithm>

#define method1 1
#define method2 0

class Solution
{
#if method1
    int maxDistToClosest(std::vector<int> &seats)
    {
        int n = seats.size(), res = 0;
        std::vector<int> nums;

        for (int i = 0; i < n; ++i)
        {
            if (seats[i] == 1)
            {
                nums.push_back(i);
            }
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (i == 0)
            {
                res = std::max(res, nums[0]);
            }
            else
            {
                res = std::max(res, (nums[i] - nums[i - 1]) / 2);
            }
        }

        if (!nums.empty()) res = std::max(res, n - 1 - nums.back());

        return res;
    }
#endif

#if method2
    int maxDistToClosest(std::vector<int> &seats)
    {
        int n = seats.size(), start = 0, res = 0;

        for (int i = 0; i < n; ++i)
        {
            if (seats[i] != 1) continue;

            if (start == 0)
            {
                res = std::max(res, i - start);
            }
            else
            {
                res = std::max(res, (i - start + 1) / 2);
            }

            start = i + 1;
        }

        res = std::max(res, n - start);

        return res;
    }
#endif
};
