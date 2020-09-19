#include <string>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    bool isIsomorphic(std::string &s, std::string &t)
    {
        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for(int i = 0; i < n; ++i)
        {
            if(m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
#endif

#if method2
    bool isIsomorphic(std::string &s, std::string &t)
    {
        int map1[256];
        int map2[256];
        memset(map1, 0, sizeof(map1));
        memset(map2, 0, sizeof(map2));
        for(int i = 0; i < s.size(); i++)
        {
            if(map1[s[i]] == 0)
            {
                map1[s[i]] = t[i];
            }
            else
            {
                if(map1[s[i]] != t[i])
                {
                    return false;
                }
            }
        }
        for(int i = 0; i < t.size(); i++)
        {
            if(map2[t[i]] == 0)
            {
                map2[t[i]] = s[i];
            }
            else
            {
                if(map2[t[i]] != s[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
#endif
};
