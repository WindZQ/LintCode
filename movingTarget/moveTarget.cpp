#include <vector>

class Solution
{
public:
    void moveTarget(std::vector<int> &nums, int target)
    {
        int count = 0;
        int left = nums.size() - 1, right = nums.size() - 1;

        while (left >= 0)
        {
            if (nums[left] != target)
            {
                nums[right] = nums[left];
                right -= 1;
            }
            else
            {
                count += 1;
            }

            left -= 1;
        }

        for (int i = 0; i < count; ++i)
        {
            nums[i] = target;
        }
    }
};
