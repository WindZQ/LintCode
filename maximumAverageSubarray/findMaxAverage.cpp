#include <vector>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    double findMaxAverage(std::vector<int> &nums, int k)
    {
        int n = nums.size();
        std::vector<int> sums = nums;
        for(int i = 0; i < n; ++i)
        {
            sums[i] = sums[i - 1] + nums[i];
        }

        double mx = sums[k - 1];
        for(int i = k; i < n; ++i)
        {
            mx = std::max(mx, (double)sums[i] - sums[i - k]);
        }

        return mx / k;
    }
#endif

#if method2
    double findMaxAverage(std::vector<int> &nums, int k)
    {
        double sum = std::accumulate(nums.begin(), nums.begin() + k, 0), res = sum;
        for(int i = k; i < nums.size(); ++i)
        {
            sum += nums[i] - nums[i - k];
            res = std::max(res, sum);
        }

        return res / k;
    }
#endif
};
