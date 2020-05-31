#include <vector>

#define method1 1
#define method2 0

class Solution
{
#if method1
    int lastPosition(std::vector<int> &nums, int target)
    {
        if(nums.size() == 0)
        {
            return -1;
        }

        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if(nums[mid] > target)
            {
                right = mid - 1;
            }
            else if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                if((mid == nums.size() - 1) || (nums[mid + 1] != target))
                {
                    return mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
#endif

#if method2
    int lastPosition(std::vector<int> &nums, int target)
    {
        if(nums.size() == 0)
        {
            return -1;
        }

        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if(nums[mid] <= target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        if(nums[left] == target) return left;
        if(nums[right] == target) return right;

        return -1;
    }
#endif
}
