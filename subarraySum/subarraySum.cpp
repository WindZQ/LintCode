#include <iostream>
#include <vector>
#include <unordered_map>

#define method1 0
#define method2 1

class Solution
{
public:
#if method1
    std::vector<int> subarraySum(std::vector<int> &nums)
    {
        std::vector<int> res;
        for(int i = 0; i < nums.size(); ++i)
        {
            int sum = 0;
            for(int j = i; j < nums.size(); ++j)
            {
                if(sum == 0)
                {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }

        res.push_back(0);
        res.push_back(0);
        return res;
    }
#endif

#if method2
    std::vector<int> subarraySum(std::vector<int> &nums)
    {
        std::unordered_map<int, int> hash;
        int sum = 0;
        hash[0] = -1;

        for(int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            if(hash.find(sum) != hash.end())
            {
                std::vector<int > res;
                res.push_back(hash[sum] + 1);
                res.push_back(i);
                return res;
            }
            hash[sum] = i;
        }

        std::vector<int> res;
        return res;
    }
#endif
};

int main(void)
{
    Solution s;
    std::vector<int> v {-3, 1, -4, 2, -3, 4};
    std::vector<int> res;
    res = s.subarraySum(v);

    for(int i = 0; i < res.size(); ++i)
        std::cout << res[i] << "\t";
    std::cout << std::endl;

    return 0;
}
