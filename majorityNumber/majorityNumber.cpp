#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
class Solution
{
public:
    //方法一：哈希表
    int majorityNumber1(std::vector<int> &nums)
    {
        std::unordered_map<int, int> map;
        int len = nums.size();
        for(int i = 0; i < len; ++i)
        {
            if(map.find(nums[i]) == map.end())
                map[nums[i]] = 0;
            else
                map[nums[i]]++;
            if(map[nums[i]] >= len / 2)
                return nums[i];
        }
    }
    //方法二：取中位数
    int majorityNumber2(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }

    //方法三：摩尔投票法
    int majorityNumber3(std::vector<int> &nums)
    {
        int majornum = nums[0], count = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(count == 0)
            {
                majornum = nums[i];
                count = 1;
            }
            else if(majornum == nums[i])
                count++;
            else
                count--;
        }
        return majornum;
    }

    //方法四：位操作法
    int majorityNumber4(std::vector<int> nums)
    {
        int res = 0, n = nums.size();
        for(int i = 0; i < 32; ++i)
        {
            int ones = 0, zeros = 0;
            for(int num : nums)
            {
                if(ones > n / 2 || zeros > n / 2)
                    break;
                if((num & (1 << i)) != 0)
                    ++ones;
                else
                    ++zeros;
            }
            if(ones > zeros)
                res |= (1 << i);
        }
        return res;
    }
};

int main()
{
    std::vector<int> v = { 1, 2, 2, 2, 3, 5, 5, 7};
    Solution s;
    std::cout << s.majorityNumber1(v) << std::endl;
    std::cout << s.majorityNumber2(v) << std::endl;
    std::cout << s.majorityNumber3(v) << std::endl;
    std::cout << s.majorityNumber4(v) << std::endl;
    return 0;
}
