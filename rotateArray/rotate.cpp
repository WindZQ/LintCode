#include <vector>

#define method1 1
#define method2 0
#define method3 0
#define method4 0
#define method5 0


class Solution
{
public:
#if method1
    std::vector<int> rotate(std::vector<int> &nums, int k)
    {
        std::vector<int> res = nums;

        for(int i = 0; i < nums.size(); ++i)
        {
            nums[(i + k) % nums.size()] = res[i];
        }

        return nums;
    }
#endif

#if method2
    std::vector<int> rotate(std::vector<int> &nums, int k)
    {
        int start = 0, index = 0, pre = 0, cur = nums[0], n = nums.size();

        for(int i = 0; i < n; ++i)
        {
            pre = cur;
            index = (index + k) % n;
            cur = nums[index];
            nums[index] = pre;

            if(index == start)
            {
                index = ++start;
                cur = nums[index];
            }
        }

        return nums;
    }
#endif

#if method3
    std::vector<int> rotate(std::vector<int> &nums, int k)
    {
        if(nums.empty() || (k %= nums.size()) == 0) return nums;

        int n = nums.size();
        std::reverse(nums.begin(), nums.begin() + n - k);
        std::reverse(nums.begin() + n - k, nums.end());
        std::reverse(nums.begin(), nums.end());

        return nums;
    }
#endif

#if method4
    std::vector<int> rotate(std::vector<int> &nums, int k)
    {
        if(nums.empty() || (k %= nums.size()) == 0) return nums;

        int n = nums.size();
        for(int i = 0; i < n - k; ++i)
        {
            nums.push_back(nums[0]);
            nums.erase(nums.begin());
        }

        return nums;
    }
#endif

#if method5
    std::vector<int> rotate(std::vector<int> &nums, int k)
    {
        if(nums.empty()) return nums;
        int n = nums.size(), start = 0;

        while(n && (k %= n))
        {
            for(int i = 0; i < k; ++i)
            {
                std::swap(nums[i + start], nums[n - k + i + start]);
            }

            n -= k;
            start += k;
        }

        return nums;
    }
#endif
};
