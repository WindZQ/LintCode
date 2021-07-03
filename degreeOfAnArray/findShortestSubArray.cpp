#include <vector>
#include <unordered_map>
#include <pair>
#include <algorithm>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    int findShortestSubArray(std::vector<int> &nums)
    {
        int n = nums.size(), res = INT_MAX, degree = 0;
        std::unordered_map<int, int> m;
        std::unordered_map<int, std::pair<int, int>> pos;

        for(int i = 0; i < nums.size(); ++i)
        {
            if(++m[nums[i]] == 1)
            {
                pos[nums[i]] = {i, i};
            }
            else
            {
                pos[nums[i]].second = i;
            }

            degree = std::max(degree, m[nums[i]]);
        }

        for(auto a : m)
        {
            if(degree == a.second)
            {
                res = std::min(res, pos[a.first].second - pos[a.first].first + 1);
            }
        }

        return res;
    }
#endif

#if method2
    int findShortestSubArray(std::vector<int> &nums)
    {
        int n = nums.size(), res = INT_MAX, degree = 0;
        std::unordered_map<int, int> m, idx;
        for(int i = 0; i < n; ++i)
        {
            ++m[nums[i]];
            if(!idx.count(nums[i])) idx[nums[i]] = i;

            if(m[nums[i]] == degree)
            {
                res = std::min(res, i - idx[nums[i]] + 1);
            }
            else if(m[nums[i]] > degree)
            {
                res = i - idx[nums[i]] + 1;
                degree = m[nums[i]];
            }
        }
        return res;
    }
#endif
};
