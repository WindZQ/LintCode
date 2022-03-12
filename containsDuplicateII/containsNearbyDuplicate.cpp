#include <vector>
#include <unordered_map>
#include <unordered_set>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    bool containsNearbyDuplicate(std::vector<int> &nums, int k)
    {
        std::unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(m.find(nums[i]) != m.end() && i - m[nums[i]] <= k)
            {
                return true;
            }
            else
            {
                m[nums[i]] = i;
            }
        }

        return false;
    }
#endif

#if method2
    bool containsNearbyDuplicate(std::vector<int> &nums, int k)
    {
        std::unordered_set<int> s;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(i > k)
            {
                s.erase(nums[i -k - 1]);
            }

            if(s.count(nums[i])) return true;
            s.emplace(nums[i]);
        }

        return false;
    }
#endif
};
