#include <string>
#include <unordered_map>

#define method1 1
#define method2 0
#define method3 0


class Solution
{
public:
#if method1
    char findTheDifference(std::string &s, std::string &t)
    {
        std::unordered_map<char, int> m;
        for(char c : s) ++m[c];
        for(char c : t)
        {
            if(--m[c] < 0) return c;
        }

        return 0;
    }
#endif

#if method2
    char findTheDifference(std::string &s, std::string &t)
    {
        char res = 0;
        for(char c : s) res ^= c;
        for(char c : t) res ^= c;
        return res;
    }
#endif

#if method3
    char findTheDifference(std::string &s, std::string &t)
    {
        char res = 0;
        for(char c : s) res -= c;
        for(char c : t) res += c;
        return res;
    }
#endif
};
