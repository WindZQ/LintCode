#include <cmath>
#include <string>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    int largestPalindrome(int n)
    {
        int upper = pow(10, n) - 1, lower = upper / 10;
        for(int i = upper; i > lower; --i)
        {
            std::string t = std::to_string(i);
            long p = stol(t + std::string(t.rbegin(), t.rend()));
            for(long j = upper; j * j > p; --j)
            {
                if(p % j == 0) return p % 1337;
            }
        }

        return 9;
    }
#endif

#if method2
    int largestPalindrome(int n)
    {
        if(n == 1) return 9;

        long long m = (int)pow(10, n);
        for(long long x = 2; x < m; x += 2)
        {
            long long upper = m - x;
            std::string s = std::to_string(upper);
            std::reverse(s.begin(), s.end());
            long long lower = stoi(s);
            long long tmp = x * x - 4 * lower;
            if(tmp < 0) continue;
            long long sq = (long long)sqrt(tmp);
            if(sq * sq == tmp)
            {
                return (int)((upper * m + lower) % 1337);
            }
        }

        return -1;
    }
#endif
};
