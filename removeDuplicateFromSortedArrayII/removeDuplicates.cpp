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
        std::vector<int> B;
        if(nums.size() == 0)
            return 0;
        int before = nums[0] - 1;
        int count = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(before != nums[i])
            {
                B.push_back(nums[i]);
                count = 1;
                before = nums[i];
            }
            else if(count < 2)
            {
                B.push_back(nums[i]);
                count++;
                before = nums[i];
            }
        }
        int len = 0;
        for(int i = 0; i < B.size(); ++i)
            nums[len++] = B[i];
        return len;
    }
#endif

#if method2
    int removeDuplicates(std::vector<int> &nums)
    {
        int pre = 0, cur = 1, cnt = 1, n = nums.size();
        while(cur < n)
        {
            if(nums[pre] == nums[cur] && cnt == 0)
            {
                ++cur;
            }
            else
            {
                if(nums[pre] == nums[cur])
                {
                    --cnt;
                }
                else
                {
                    cnt = 1;
                }
                nums[++pre] = nums[cur++];
            }
        }
        return nums.empty() ? 0 : pre + 1;
    }
#endif

#if method3
    int removeDuplicates(std::vector<int> &nums)
    {
        int i = 0;
        for(int num : nums)
        {
            if(i < 2 || num > nums[i - 2])
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
