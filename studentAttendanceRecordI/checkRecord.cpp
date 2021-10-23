#include <string>
#include <regex>

#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
    bool checkRecord(std::string &s)
    {
        int cnt_a = 0, cnt_l = 0;
        for(char c : s)
        {
            if(c == 'A')
            {
                if(++cnt_a > 1) return false;
                cnt_l = 0;
            }
            else if(c == 'L')
            {
                if(++cnt_l > 2) return false;
            }
            else
            {
                cnt_l = 0;
            }
        }

        return true;
    }
#endif

#if method2
    bool checkRecord(std::string &s)
    {
        return (s.find("A") == std::string::npos || s.find("A") == s.rfind("A")) && s.find("LLL") == std::string::npos;
    }
#endif

#if method3
    bool checkRecord(std::string &s)
    {
        return !std::regex_search(s, std::regex("A.*A|LLL"));
    }
#endif
};
