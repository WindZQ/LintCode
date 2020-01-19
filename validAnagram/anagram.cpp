#include <iostream>
#include <string>
#include <algorithm>

#define method1 0
#define method2 0
#define method3 1

class Solution
{
public:
#if method1
    bool anagram(std::string &s, std::string &t)
    {
        int set_s[256] = {0}, set_t[256] = {0};
        for(int i = 0; i < s.length(); ++i)
        {
            set_s[s[i]]++;
        }

        for(int i = 0; i < t.length(); ++i)
        {
            set_t[t[i]]++;
        }

        for(int i = 0; i < 256; ++i)
        {
            if(set_t[i] != set_s[i])
            {
                return false;
            }
        }

        return true;
    }
#endif

#if method2
    bool anagram(std::string &s, std::string &t)
    {
        if(s.size() != t.size()) return false;
        int m[26] = {0};
        for(int i = 0; i < s.size(); ++i)
        {
            ++m[s[i] - 'a'];
        }
        for(int i = 0; i < t.size(); ++i)
        {
            if(--m[t[i] - 'a'] < 0)
            {
                return false;
            }
        }

        return true;
    }
#endif

#if method3
    bool anagram(std::string &s, std::string &t)
    {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        return s == t;
    }
#endif
};

int main(void)
{
    std::string str = "ab";
    std::string t = "ba";
    Solution s;
    bool result;
    result = s.anagram(str, t);
    if(result)
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }

    return 0;
}
