#include <vector>
#include <set>
#include <algorithm>

#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
    int thirdMax(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end(), greater<>());

        for(int i = 1, diff = 1; i < nums.size(); ++i)
        {
            if(nums[i] != nums[i - 1] && ++diff == 3)
            {
                return nums[i];
            }
        }

        return nums[0];
    }
#endif

#if method2
    int thirdMax(std::vector<int> &nums)
    {
        std::set<int> s;
        for(int num : nums)
        {
            s.insert(num);
            if(s.size() > 3)
            {
                s.erase(s.begin());
            }
        }

        return s.size() == 3 ? *s.begin() : *s.rbegin();
    }
#endif

#if method3
    int thirdMax(std::vector<int> &nums)
    {
        int *a = nullptr, *b = nullptr, *c = nullptr;
        for(int &num : nums)
        {
            if(a == nullptr || num > *a)
            {
                c = b;
                b = a;
                a = &num;
            }
            else if(*a > num && (b == nullptr || num > *b))
            {
                c = b;
                b = &num;
            }
            else if(b != nullptr && *b > num && (c == nullptr || num > *c))
            {
                c = &num;
            }
        }

        return c == nullptr ? *a : *c;
    }
#endif
};
