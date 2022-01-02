#include <vector>
#include <math>
#include <algorithm>

#define method1 1
#define method2 0
#define method3 0


class Solution
{
public:
#if method1
    std::vector<int> findDisappearedNumbers(std::vector<int> &nums)
    {
        std::vector<int> res;
        for(int i = 0; i <nums.size(); ++i)
        {
            int idx = std::abs(nums[i]) - 1;
            nums[idx] = (nums[idx] > 0) ? -nums[idx] : nums[idx];
        }

        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] > 0)
            {
                res.push_back(i + 1);
            }
        }

        return res;
    }
#endif

#if method2
    std::vector<int> findDisappearedNumbers(std::vector<int> &nums)
    {
        std::vector<int> res;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != nums[nums[i] - 1])
            {
                std::swap(nums[i], nums[nums[i] - 1]);
                --i;
            }
        }

        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != i + 1)
            {
                res.push_back(i + 1);
            }
        }

        return res;
    }
#endif

#if method3
    std::vector<int> findDisappearedNumbers(std::vector<int> &nums)
    {
        std::vector<int> res;
        int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            nums[(nums[i] - 1) % n] += n;
        }

        for(int i = 0; i < n; ++i)
        {
            if(nums[i] <= n)
            {
                res.push_back(i + 1);
            }
        }

        return res;
    }
#endif
};
