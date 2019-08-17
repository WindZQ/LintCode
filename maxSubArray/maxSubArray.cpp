#include <iostream>
#include <vector>

#define dp1     0
#define al1     1

#if al1
//方法一：分治思想
class Solution
{
public:
    int maxSubArray(std::vector<int> &nums)
    {
        return find(nums, 0, nums.size() - 1);
    }

    int find(std::vector<int> nums, int start, int end)
    {
        if(start == end)
            return nums[start];
        if(start > end)
            return INT_MIN;

        int left_max = 0, right_max = 0, ml = 0, mr = 0;
        int mid = (start + end) >> 1;

        left_max = find(nums, start, mid - 1);
        right_max = find(nums, mid + 1, end);

        for(int i = mid - 1, sum = 0; i >= start; --i)
        {
            sum += nums[i];
            if(sum > ml)
                ml = sum;
        }

        for(int i = mid + 1, sum = 0; i <= end; ++i)
        {
            sum += nums[i];
            if(sum > mr)
                mr = sum;
        }
        return std::max(std::max(left_max, right_max), ml + mr + nums[mid]);
    }
};
#endif
#if dp1
//方法二：动态规划
class Soluction
{
public:
    int  maxSubArray(std::vector<int> &nums)
    {
        if(nums.size() == 0)
            return 0;
        std::vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int max = dp[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            dp[i] = nums[i] > nums[i] + dp[i - 1] ? nums[i] : nums[i] + dp[i - 1];
            if(dp[i] > max) max = dp[i];
        }
        return max;
    }
};
#endif

int main()
{
    std::vector<int> v {-2, 2, -3, 4, -1, 2, 1, -5, 3};
    Solution s;
    std::cout << s.maxSubArray(v) << std::endl;
    return 0;
}
