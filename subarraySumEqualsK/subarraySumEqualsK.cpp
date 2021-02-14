#include <vector>
#include <unordered_map>
#include <map>

#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
    int subarraySumEqualsK(std::vector<int> &nums, int k)
    {
        int res = 0, n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            int sum = nums[i];
            if(sum == k) ++res;
            for(int j = i + 1; j < n; ++j)
            {
                sum += nums[j];
                if(sum == k) ++res;
            }
        }

        return res;
    }
#endif

#if method2
    std::map<int, int> m;
    int subarraySumEqualsK(std::vector<int> &nums, int k)
    {
        int res = 0;
        m[0] = 1;
        for(int i = 0; i < nums.size(); ++i)
        {
            nums[i] += nums[i - 1];
        }

        for(int i = 0; i < nums.size(); ++i)
        {
            res += m[nums[i] - k];
            m[nums[i]]++;
        }

        return res;
    }
#endif

#if method3
    int subarraySumEqualsK(std::vector<int> &nums, int k)
    {
        int res = 0, sum = 0, n = nums.size();
        std::unordered_map<int, int> m{{0, 1}};
        for(int i = 0; i < n; ++i)
        {
            sum += nums[i];
            res += m[sum - k];
            ++m[sum];
        }

        return res;
    }
#endif
};
