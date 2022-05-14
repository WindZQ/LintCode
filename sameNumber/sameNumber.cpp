#include <map>
#include <unordered_map>
#include <string>
#include <vector>


#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
    std::string sameNumber(std::vector<int> &nums, int k)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < i + k; ++j)
            {
                if (nums[i] == nums[j])
                {
                    return "YES";
                }
            }
        }

        return "NO";
    }
#endif

#if method2
    std::string sameNumber(std::vector<int> &nums, int k)
    {
        std::unordered_map<int, int> h;
        h.clear();

        for (int i = 0; i < nums.size(); ++i)
        {
            if (h.find(nums[i]) != h.end())
            {
                if (i - h[nums[i]] < k)
                {
                    return "YES";
                }
            }

            h[nums[i]] = i;
        }

        return "NO";
    }
#endif

#if method3
    std::string sameNumber(std::vector<int> &nums, int k)
    {
        std::map<int, int> m;
        bool res = false;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (m.find(nums[i]) == m.end())
            {
                m[nums[i]] = i;
            }
            else
            {
                if(i - m[nums[i]] < k)
                {
                    res = true;
                    break;
                }

                m[nums[i]] = i;
            }
        }

        if (res == true)
        {
            return "YES";
        }
        else
        {
            return "NO";
        }
    }
#endif
};
