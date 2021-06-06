#include <vector>

#define method1 1
#define method2 0

class Solution
{
#if method1
    int dominantIndex(std::vector<int> &nums)
    {
        int mx = INT_MIN, second_mx = INT_MIN, mx_id = 0;

        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] > mx)
            {
                second_mx = mx;
                mx = nums[i];
                mx_id = i;
            }
            else if(nums[i] > second_mx)
            {
                second_mx = nums[i];
            }
        }

        return (mx - second_mx >= second_mx) ? mx_id : -1;
    }
#endif

#if method2
    int dominantIndex(std::vector<int> &nums)
    {
        int mx = INT_MIN, mx_id = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(mx < nums[i])
            {
                mx = nums[i];
                mx_id = i;
            }
        }

        for(int num : nums)
        {
            if(mx != num && mx - num < num)
            {
                return -1;
            }
        }

        return mx_id;
    }
#endif
};
