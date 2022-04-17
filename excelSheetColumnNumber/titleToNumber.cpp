#include <string>
#include <numeric>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    int titileToNumber(std::string &s)
    {
        int res = 0;
        long mul = 1;
        int length = s.size();

        for(int i = length - 1; i >= 0; --i)
        {
            int k = s[i] - 'A' + 1;
            res += k * mul;
            mul *= 26;
        }

        return res;
    }
#endif

#if method2
    int titileToNumber(std::string &s)
    {
        return accumulate(begin(s), end(s), int(), [](const int &sum, const char &c) { return sum * 26 - 'A' + 1 + c;});
    }
#endif
};
