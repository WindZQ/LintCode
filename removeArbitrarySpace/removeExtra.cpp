#include <string>
#include <regex>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    std::string removeExtra(std::string &s)
    {
        std::string ans;
        for(int i = 0; i < s.size();)
        {
            if(s[i] == ' ')
            {
                bool flag = i != 0;
                while(i < s.size() && s[i] == ' ')
                {
                    ++i;
                }
                if(flag && i != s.size())
                {
                    ans += ' ';
                }
            }

            while(i < s.size() && s[i] != ' ')
            {
                ans += s[i];
                ++i;
            }
        }
        return ans;
    }
#endif

#if method2
    std::string removeExtra(std::string &s)
    {
        return std::regex_replace(s, std::regex("^ +| +$|( ) +"), "$1");
    }
#endif
};
