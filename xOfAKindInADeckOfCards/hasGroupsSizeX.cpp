#include <vector>
#include <unordered_map>

#define method1 1
#define method2 0


class Solution
{
public:
#if method1
    bool hasGroupsSizeX(std::vector<int> &deck)
    {
        std::unordered_map<int, int> card_cnt;
        for (int card : deck) ++card_cnt[card];

        int mn = INT_MAX;
        for (auto &a : card_cnt) mn = std::min(mn, a.second);
        if (mn < 2) return false;

        for (int i = 2;i <= mn; ++i)
        {
            bool success = true;
            for (auto &a : card_cnt)
            {
                if (a.second % i != 0)
                {
                    success = false;
                    break;
                }
            }

            if (success) return true;
        }

        return false;
    }
#endif

#if method2
    bool hasGroupsSizeX(std::vector<int> &deck)
    {
        std::unordered_map<int, int> card_cnt;
        for (int card : deck) ++card_cnt[card];

        int res = 0;
        for (auto &a : card_cnt) res = gcd(a.second, res);

        return res > 1;
    }

    int gcd(int a, int b)
    {
        return a == 0 ? b : gcd(b % a, a);
    }
#endif
};
