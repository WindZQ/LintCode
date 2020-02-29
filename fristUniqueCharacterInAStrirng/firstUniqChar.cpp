#include <iostream>
#include <string>

#define method1 1

class Solution
{
public:
#if method1
    char firstUniqChar(std::string &str)
    {
        int vis[256] = {0};
        for(int i = 0; i < str.length(); ++i)
        {
            vis[str[i]]++;
        }

        for(int i = 0; i < 256; ++i)
        {
            if(vis[i] == 1)
            {
                return i;
            }
        }
    }
#endif
};
