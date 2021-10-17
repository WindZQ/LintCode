#include <string>
#include <algorithm>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    std::string reverseWords(std::string &s)
    {
        if(s == "") return s;
        std::string res = "", t = "";
        istringstream is(s);
        while(is >> t)
        {
            std::reverse(t.begin(), t.end());
            res += t + " ";
        }

        res.pop_back();

        return res;
    }
#endif

#if method2
    std::string reverseWords(std::string &s)
    {
        int start = 0, end = 0, n = s.size();

        while(start < n && end <n)
        {
            while(end < n && s[end] != ' ') ++end;

            for(int i = start, j = end - 1; i < j; ++i, --j)
            {
                std::swap(s[i], s[j]);
            }
            start = ++end;
        }

        return s;
    }
#endif
};
