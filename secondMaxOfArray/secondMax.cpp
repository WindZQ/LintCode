#include <vector>


#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
    int secondMax(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() - 2];
    }
#endif

#if method2
    int secondMax(std::vector<int> &nums)
    {
        int mmax = std::max(nums[0], nums[1]);
        int second = std::min(nums[0], nums[1]);

        for(int i = 2; i < nums.size(); ++i)
        {
            if(nums[i] > mmax)
            {
                second = mmax;
                mmax = nums[i];
            }
            else if(nums[i] > second)
            {
                second = nums[i];
            }
        }

        return second;
    }
#endif

#if method3
    int secondMax(std::vector<int> &nums)
    {
        quick_sort(nums, 0, nums.size() - 1);
        return nums[nums.size() - 2];
    }

    void quick_sort(std::vector<int> &nums, int start, int end)
    {
        if(start >= end) return ;
        int pos = partition(nums, start, end);
        quick_sort(nums, start, pos - 1);
        quick_sort(nums, pos, end);
    }

    int partition(std::vector<int> &nums, int start, int end)
    {
        int i = start - 1, pivot = nums[end];
        for(int j = start; j < end; ++j)
        {
            if(nums[j] <= pivot)
            {
                ++i;
                std::swap(nums[i], nums[j]);
            }
        }

        std::swap(nums[i + 1], nums[end]);
        return i + 1;
    }
#endif
};
