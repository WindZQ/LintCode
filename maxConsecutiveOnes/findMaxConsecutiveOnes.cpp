#include <vector>
#include <algorithm>

#define method1 1
#define method2 0


class Solution
{
public:
#if method1
    int findMaxConsecutiveOnes(std::vector<int> &nums)
    {
        int res = 0, cnt = 0;
        for(int num : nums)
        {
            cnt = (num == 0) ? 0 : cnt + 1;
            res = std::max(res, cnt);
        }

        return res;
    }
#endif

#if method2
    int findMaxConsecutiveOnes(std::vector<int> &nums)
    {
        int res = 0, sum = 0;
        for(int num : nums)
        {
            sum = (sum + num) * num;
            res = std::max(res, sum);
        }

        return res;
    }
#endif
};
