#include <iostream>
#include <vector>
#include <algorithm>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    void partitionArray(std::vector<int> &nums)
    {
        if(nums.empty()) return;

        int i = 0, j = nums.size() - 1;
        while(i < j)
        {
            while(i < j && nums[i] % 2 != 0) ++i;
            while(i < j && nums[j] % 2 == 0) --j;
            if(i != j) std::swap(nums[i], nums[j]);
        }
    }
#endif

#if method2
    void partitionArray(std::vector<int> &nums)
    {
        int start = 0, end = nums.size() - 1;
        while(start < end)
        {
            while(start < end && nums[start] % 2 == 1) ++start;
            while(start < end && nums[end] % 2 == 0) --end;
            if(start < end) swap(nums[start++], nums[end--]);
        }
        int i = 0;
        for(; i < nums.size(); ++i)
        {
            if(nums[i] % 2 == 0) break;
        }
        if(i > 0) swap(nums[0], nums[i - 1]);
    }
#endif
};
