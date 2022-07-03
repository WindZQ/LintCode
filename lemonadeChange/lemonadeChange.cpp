#include <vector>
#include <unordered_map>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    bool lemonadeChange(std::vector<int> &bills)
    {
        std::unordered_map<int, int> cnt;

        for (int bill : bills)
        {
            ++cnt[bill];
            if (cnt[5] < cnt[20] + cnt[10]) return false;
            if (cnt[5] < 3 * cnt[20] - cnt[10]) return false;
        }

        return true;
    }
#endif

#if method2
    bool lemonadeChange(std::vector<int> &bills)
    {
        int five = 0, ten = 0;

        for (int bill : bills)
        {
            if (bill == 5)
            {
                ++five;
            }
            else if (bill == 10)
            {
                --five;
                ++ten;
            }
            else if (ten > 0)
            {
                --ten;
                --five;
            }
            else
            {
                five -= 3;
            }

            if (five < 0) return false;
        }

        return true;
    }
#endif
};
