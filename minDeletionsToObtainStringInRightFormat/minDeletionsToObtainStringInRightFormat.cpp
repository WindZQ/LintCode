#include <string>
#include <algorithm>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    int minDeletionsToObtainStringInRightFormat(std::string &s)
    {
        int rhs = 0, lhs = 0, res = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == 'A') ++rhs;
        }
        res = rhs;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == 'A')
            {
                --rhs;
            }
            else
            {
                ++lhs;
            }

            res = std::min(res, rhs + lhs);
        }

        return res;
    }
#endif

#if method2
    int minDeletionsToObtainStringInRightFormat(std::string &s)
    {
        int res = 0, a = 0, b = 0;

        for (char c : s)
        {
            if (c == 'A')
            {
                a++;
            }
            else if (a > 0)
            {
                if (a > b)
                {
                    res += b;
                    a = 0;
                    b = 0;
                }
                b++;
            }
            else
            {
                b++;
            }
        }

        if (a <= b) res += a;

        return res;
    }
#endif
};
