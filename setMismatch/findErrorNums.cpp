#include <vector>
#include <algorithm>


#define method1 1
#define method2 0
#define method3 0


class Solution
{
public:
#if method1
    std::vector<int> findErrorNums(std::vector<int> &nums)
    {
        std::vector<int> res(2, 0), cnt(nums.size(), 0);
        for(int num : nums) ++cnt[num - 1];
        for(int i = 0; i < cnt.size(); ++i)
        {
            if(res[0] != 0 && res[1] != 0) return res;
            if(cnt[i] == 2) res[0] = i + 1;
            else if(cnt[i] == 0) res[1] = i + 1;
        }

        return res;
    }
#endif

#if method2
    std::vector<int> findErrorNums(std::vector<int> &nums)
    {
        std::vector<int> res(2, -1);
        for(int i : nums)
        {
            if(nums[std::abs(i) - 1] < 0) res[0] = std::abs(i);
            else nums[abs(i) - 1] *= -1;
        }

        for(int i = 0; i< nums.size(); ++i)
        {
            if(nums[i] > 0)
            {
                res[1] = i + 1;
            }
        }

        return res;
    }
#endif

#if method3
    std::vector<int> findErrorNums(std::vector<int> &nums)
    {
        for(int i = 0; i < nums.size(); ++i)
        {
            while(nums[i] != nums[nums[i] - 1])
            {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != i + 1)
            {
                return {nums[i], i + 1};
            }
        }
    }
#endif
};
