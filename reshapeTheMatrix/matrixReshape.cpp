#include <vector>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>> &nums, int r, int c)
    {
        int m = nums.size(), n = nums[0].size();
        if(m * n != r * c) return nums;
        std::vector<std::vector<int>> res(r, std::vector<int> (c));

        for(int i = 0; i < r; ++i)
        {
            for(int j = 0; j < c; ++j)
            {
                int k = i * c + j;
                res[i][j] = nums[k / n][k % n];
            }
        }

        return res;
    }
#endif

#if method2
    std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>> &nums, int r, int c)
    {
        int m = nums.size(), n = nums[0].size();
        if(m * n != r * c) return nums;
        std::vector<std::vector<int>> res(r, std::vector<int> (c));
        for(int i = 0; i < r * c; ++ i)
        {
            res[i / c][i % c] = nums[i / n][i % n];
        }

        return res;
    }
#endif
};
