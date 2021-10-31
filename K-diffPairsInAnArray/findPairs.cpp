#include <vector>
#include <unordered_map>
#include <algorithm>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    int findPairs(std::vector<int> &nums, int k)
    {
        int res = 0, n = nums.size();
        std::unordered_map<int, int> m;
        for(int num : nums) ++m[num];

        for(auto a : m)
        {
            if(k == 0 && a.second > 1) ++res;
            if(k > 0 && m.count(a.first + k)) ++res;
        }

        return res;
    }
#endif

#if method2
    int findPairs(std::vector<int> &nums, int k)
    {
        int res = 0, n = nums.size(), j = 0, pre = INT_MAX;
        std::sort(nums.begin(), nums.end());

        for(int i = 1; i < n; ++i)
        {
            while(j < i && nums[i] - nums[j] > k) ++j;
            if(j != i && pre != nums[j] && nums[i] - nums[j] == k)
            {
                ++res;
                pre = nums[j];
            }
        }

        return res;
    }
#endif
};
