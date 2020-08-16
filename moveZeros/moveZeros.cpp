#include <vector>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    void moveZeros(std::vector<int> &nums)
    {
        for(int i = 0, j = 0; i < nums.size(); ++i)
        {
            if(nums[i])
            {
                std::swap(nums[i], nums[j++]);
            }
        }
    }
#endif

#if method2
    void moveZeros(std::vector<int> &nums)
    {
        int left = 0, right = 0;
        while(right < nums.size())
        {
            if(nums[right] != 0)
            {
                nums[left] = nums[right];
                left++;
            }
            right++;
        }

        while(left < nums.size())
        {
            nums[left] = 0;
            left++;
        }
    }
#endif
};
