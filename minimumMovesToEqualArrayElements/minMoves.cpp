#include <vector>
#include <algorithm>

#define method1 1
#define method2 0


class Solution
{
public:
#if method1
    int minMoves(std::vector<int> &nums)
    {
        int min_num = *min_element(nums.begin(), nums.end());
        int res = 0;
        for(int num : nums)
        {
            res += num - min_num;
        }

        return res;
    }
#endif

#if method2
    int minMoves(std::vector<int> &nums)
    {
        int small = nums[0];
        int res = 0;

        for(auto n : nums)
        {
            small = std::min(small, n);
        }

        for(auto n : nums)
        {
            res += n - small;
        }

        return res;
    }
#endif
};
