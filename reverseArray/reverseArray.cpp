#include <vector>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    void reverseArray(std::vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        int tmp = 0;

        while(left < right)
        {
            tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            left++;
            right--;
        }
    }
#endif

#if method2
    void reverseArray(std::vector<int> &nums)
    {
        for(int i = 0; i < nums.size() / 2; ++i)
        {
            int tmp = nums[i];
            nums[i] = nums[nums.size() - i - 1];
            nums[nums.size() - i - 1] = tmp;
        }
    }
#endif
};
