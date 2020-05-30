#include <vector>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1 1
    int findPosition(std::vector<int> &nums, int target)
    {
        if(nums.size() == 0)
            return -1;

        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        if(nums[left] == target)
        {
            return left;
        }
        if(nums[right] == target)
        {
            return right;
        }

        return -1;
    }
#endif

#if method2
    int findPosition(std::vector<int> &nums, int target)
    {
        if(nums.size() == 0)
        {
            return -1;
        }
        return helper(nums, target, 0, nums.size() - 1);
    }

    int helper(std::vector<int> &nums, int target, int left, int right)
    {
        if(left > right)
        {
            return -1;
        }

        int mid = left + ((right - left) >> 1);
        if(nums[mid] == target)
        {
            return mid;
        }
        else  if(nums[mid] > target)
        {
            return helper(nums, target, left, mid - 1);
        }
        else
        {
            return helper(nums, target, mid + 1, right);
        }
    }
#endif
};
