#include <iostream>
#include <vector>
#define method1 0
#define method2 0
#define method3 1

class Solution
{
public:
    //常规方法 时间复杂度为O(n^2),空间复杂为O(n)
#if method1
    std::vector<long long> productExcludeItself(std::vector<int> &nums)
    {
        std::vector<long long> res;
        for(int i = 0; i < nums.size(); ++i)
        {
            long long temp = 1;
            for(int j = 0; j < nums.size(); ++j)
            {
                if(i == j)
                    continue;
                temp *= nums[j];
            }
            res.push_back(temp);
        }
        return res;
    }
#endif

    //forward-backward traveral 时间复杂度为O(n)
#if method2
    std::vector<long long> productExcludeItself(std::vector<int> &nums)
    {
        std::vector<long long> forward(nums.size(), 1), backward(nums.size(), 1), res(nums.size());
        for(int i = 0; i < nums.size() - 1; ++i)
            forward[i + 1] = forward[i] * nums[i];
        for(int i = nums.size() - 1; i > 0; --i)
            backward[i - 1] = backward[i] * nums[i];
        for(int i = 0; i < nums.size(); ++i)
            res[i] = forward[i] * backward[i];
        return res;
    }

#endif
    //方法三：在方法二的基础上进行了优化
#if method3
    std::vector<long long> productExcludeItself(std::vector<int> &nums)
    {
        std::vector<long long> res(nums.size(), 1);
        for(int i = 1; i < nums.size(); ++i)
            res[i] = res[i - 1] * nums[i - 1];
        int right = 1;
        for(int i = nums.size() - 1; i >= 0; --i)
        {
            res[i] *= right;
            right *= nums[i];
        }
        return res;
    }
#endif
};


int main()
{
    Solution s;
    std::vector<int> v {2, 4, 6};
    std::vector<long long> result;
    result = s.productExcludeItself(v);
    for(int i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\t";
    std::cout << std::endl;
    return 0;
}
