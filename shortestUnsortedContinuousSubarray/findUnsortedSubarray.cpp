#include <vector>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    int findUnsortedSubarray(std::vector<int> &nums)
    {
        int n = nums.size(), i = 0, j = n -1;
        std::vector<int> t = nums;
        std::sort(t.begin(), t.end());
        while(i < n && nums[i] == t[i]) ++i;
        while(j > i && nums[j] == t[j]) --j;
        return j - i + 1;
    }
#endif

#if method2
    int findUnsortedSubarray(std::vector<int> &nums)
    {
        int n = nums.size(), start = -1, end = -2;
        int mn = nums[n - 1], mx = nums[0];

        for(int i = 1; i < n; ++i)
        {
            mx = std::max(mx, nums[i]);
            mn = std::min(mn, nums[n - 1 - i]);
            if(mx > nums[i]) end = i;
            if(mn < nums[n - 1 - i]) start = n - 1 - i;
        }

        return end - start + 1;
    }
#endif
};
