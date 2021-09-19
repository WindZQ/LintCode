#include <vector>
#include <map>

#define method1 1
#define method2 0
#define method3 0
#define method4 0


class Solution
{
public:
#if method1
    int findLHS(std::vector<int> &nums)
    {
        if(nums.empty()) return 0;
        int res = 0;
        std::map<int, int> m;
        for(int num : nums) ++m[num];
        for(auto it = next(m.begin()); it != m.end(); ++it)
        {
            auto pre = prev(it);
            if(it->first == pre->first + 1)
            {
                res = std::max(res, it->second + pre->second);
            }
        }

        return res;
    }
#endif

#if method2
    int findLHS(std::vector<int> &nums)
    {
        int res = 0;
        std::unordered_map<int, int> m;
        for(int num : nums) ++m[num];
        for(auto a : m)
        {
            if(m.count(a.first + 1))
            {
                res = std::max(res, m[a.first] + m[a.first + 1]);
            }
        }

        return res;
    }
#endif

#if method3
    int findLHS(std::vector<int> &nums)
    {
        int res = 0;
        std::unordered_map<int, int> m;
        for(int num : nums)
        {
            ++m[num];
            if(m.count(num + 1))
            {
                res = std::max(res, m[num] + m[num + 1]);
            }

            if(m.count(num - 1))
            {
                res = std::max(res, m[num] + m[num - 1]);
            }
        }

        return res;
    }
#endif

#if method4
    int findLHS(std::vector<int> &nums)
    {
        int res = 0, start = 0, new_start = 0;
        std::sort(nums.begin(), nums.end());

        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] - nums[start] > 1) start = new_start;
            if(nums[i] != nums[i - 1]) new_start = i;
            if(nums[i] - nums[start] == 1) res = std::max(res, i - start + 1);
        }

        return res;
    }
#endif
};
