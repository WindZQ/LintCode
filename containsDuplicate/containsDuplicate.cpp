#include <vector>
#include <unordered_set>
#include <unordered_map>

#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
    bool containsDuplicate(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i = 0; i < n - 1; ++i)
        {
            if(nums[i] == nums[i + 1]) return true;
        }

        return false;
    }
#endif

#if method2
    bool containsDuplicate(std::vector<int> &nums)
    {
        std::unordered_set<int> s;

        for(int x : nums)
        {
            if(s.find(x) != s.end()) return true;
            s.insert(x);
        }

        return false;
    }
#endif

#if method3
    bool containsDuplicate(std::vector<int> &nums)
    {
        std::unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(m.find(nums[i]) != m.end()) return true;
            ++m[nums[i]];
        }

        return false;
    }
#endif
};
