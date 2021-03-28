#include <vector>

#define method1 1
#define method2 0


class NumArray
{
public:
#if method1
    std::vector<int> sum;
    NumArray(std::vector<int> nums)
    {
        sum.push_back(0);
        for(int i = 1; i <= nums.size(); ++i)
        {
            sum.push_back(sum.back() + nums[i - 1]);
        }
    }

    int sumRange(int i, int j)
    {
        return sum[j + 1] - sum[i];
    }
#endif

#if method2
    std::vector<int> sum;
    NumArray(std::vector<int> nums)
    {
        for(int i = 0; i < nums.size(); ++i)
        {
            int x = nums[i];

            if(i == 0)
            {
                sum.push_back(x);
            }
            else
            {
                sum.push_back(x + sum[i - 1]);
            }
        }
    }

    int sumRange(int i, int j)
    {
        if(i == 0)
        {
            return sum[j];
        }
        else
        {
            return sum[j] - sum[i - 1];
        }
    }
#endif

};
