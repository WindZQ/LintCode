#include <string>
#include <algorithm>

#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
    std::string convertToTitle(int n)
    {
        std::string res = "";

        while (n)
        {
            if (n % 26 == 0)
            {
                res += 'Z';
                n -= 26;
            }
            else
            {
                res += n % 26 - 1 + 'A';
                n -= n % 26;
            }

            n /= 26;
        }

        std::reverse(res.begin(), res.end());

        return res;
    }
#endif

#if method2
    std::string convertToTitle(int n)
    {
        std::string res;

        while (n)
        {
            res += --n % 26 + 'A';
            n /= 26;
        }

        return std::string(res.rbegin(), res.rend());
    }
#endif

#if method3
    std::string convertToTitle(int n)
    {
        return n == 0 ? "" : convertToTitle(n / 26) + (char)(--n % 26 + 'A');
    }
#endif
};
