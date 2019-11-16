#include <iostream>
#include <vector>

#define method1 0
#define method2 0
#define method3 1

class Solution
{
public:
#if method1
    int removeDuplicates(std::vector<int> &nums)
    {
        if(nums.size() == 0)
        {
            return 0;
        }

        int len = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[len] != nums[i])
            {
                nums[++len] = nums[i];
            }
        }
        return len + 1;
    }
#endif

#if method2
    int removeDuplicates(std::vector<int> &nums)
    {
        int pre = 0, cur = 0, n = nums.size();
        while(cur < n)
        {
            if(nums[pre] == nums[cur])
            {
                ++cur;
            }
            else
            {
                nums[++pre] = nums[cur++];
            }
        }
        return nums.empty() ? 0 : (pre + 1);
    }
#endif

#if method3
    int removeDuplicates(std::vector<int> &nums)
    {
        int i = 0;
        for(int num : nums)
        {
            if(i < 1 || num > nums[i - 1])
            {
                nums[i++] = num;
            }
        }
        return i;
    }
#endif
};

int main(void)
{
    Solution s;
    std::vector<int> v {1, 1, 1, 2, 3, 3};
    for(int i = 0; i < v.size(); ++i)
        std::cout << v[i] << "\t";
    std::cout << std::endl;
    std::cout << s.removeDuplicates(v) << std::endl;
    for(int i = 0; i < v.size(); ++i)
        std::cout << v[i] << "\t";
    std::cout << std::endl;
    return 0;
}
