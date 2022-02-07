#include <string>
#include <algorithm>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    std::string reverseString(std::string &s)
    {
        int left = 0, right = s.size() - 1;
        while(left < right)
        {
            char t = s[left];
            s[left++] = s[right];
            s[right--] = t;
        }

        return s;
    }
#endif

#if method2
    std::string reverseString(std::string &s)
    {
        int left = 0, right = s.size() - 1;
        while(left < right)
        {
            std::swap(s[left++], s[right--]);
        }

        return s;
    }
#endif
};
