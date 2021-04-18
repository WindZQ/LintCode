#include <vector>
#include <algorithm>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    int arrayPairSum(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        int res = 0;
        for(int i = 0; i < nums.size(); i += 2)
        {
            res += nums[i];
        }

        return res;
    }
#endif

#if method2
    int arrayPairSum(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        int index = 0, res = 0;
        while(index < nums.size())
        {
            res += nums[index];
            index += 2;
        }

        return res;
    }
#endif
};
