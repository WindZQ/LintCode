#include <vector>

#define method1 1
#define method2 0

class Solution
{
#if method1
    int pivotIndex(std::vector<int> &nums)
    {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        int cur_sum = 0, n = nums.size();

        for(int i = 0; i < n; ++i)
        {
            if(sum - nums[i] == 2 * cur_sum)
            {
                return i;
            }
            cur_sum += nums[i];
        }

        return -1;
    }
#endif

#if method2
    int pivotIndex(std::vector<int> &nums)
    {
        int sum = 0, left = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
        }

        for(int i = 0; i < nums.size(); ++i)
        {
            if(i != 0)
            {
                left += nums[i - 1];
            }

            if(sum - left - nums[i] == left)
            {
                return i;
            }
        }

        return -1;
    }
#endif
}
