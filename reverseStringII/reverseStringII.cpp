#include <string>
#include <algorithm>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    std::string reverseStringII(std::string &s, int k)
    {
        int n = s.size(), cnt = n / k;

        for(int i = 0; i <= cnt; ++i)
        {
            if(i % 2 == 0)
            {
                if(i * k + k < n)
                {
                    std::reverse(s.begin() + i * k, s.begin() + i * k + k);
                }
                else
                {
                    std::reverse(s.begin() + i * k, s.end());
                }
            }
        }

        return s;
    }
#endif

#if method2
    std::string reverseStringII(std::string &s, int k)
    {
        for(int i = 0; i < s.size(); i += 2 * k)
        {
            std::reverse(s.begin() + i, std::min(s.begin() + i + k, s.end()));
        }

        return s;
    }
#endif
};
