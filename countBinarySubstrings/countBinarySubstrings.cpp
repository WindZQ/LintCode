#include <string>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    int countBinarySubstrings(std::string &s)
    {
        int zeros = 0, ones = 0, res = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(i == 0)
            {
                (s[i] == '1') ? ++ones : ++zeros;
            }
            else
            {
                if(s[i] == '1')
                {
                    ones = (s[i - 1] == '1') ? ones + 1 : 1;
                    if(zeros >= ones) ++res;
                }
                else if(s[i] == '0')
                {
                    zeros = (s[i - 1] == '0') ? zeros + 1 : 1;
                    if(ones >= zeros) ++res;
                }
            }
        }
        return res;
    }
#endif

#if method2
    int countBinarySubstrings(std::string &s)
    {
        int res = 0, pre = 0, cur = 1, n = s.size();
        for(int i = 1; i < n; ++i)
        {
            if(s[i] == s[i - 1]) ++cur;
            else
            {
                pre = cur;
                cur = 1;
            }

            if(pre >= cur) ++res;
        }

        return res;
    }
#endif
};
