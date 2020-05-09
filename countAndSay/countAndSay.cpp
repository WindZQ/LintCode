#include <iostream>
#include <string>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    std::string countAndSay(int n)
    {
        if(n <= 0) return "";
        std::string res = "1";
        while(--n)
        {
            std::string cur = "";
            for(int i = 0; i < res.size(); ++i)
            {
                int cnt = 1;
                while(i + 1 < res.size() && res[i] == res[i + 1])
                {
                    ++cnt;
                    ++i;
                }
                cur += to_string(cnt) + res[i];
            }
            res = cur;
        }
        return res;
    }
#endif

#if method2
    std::string int_to_string(int j)
    {
        std::stringstream in;
        in << j;
        std::string temp;
        in >> temp;
        return temp;
    }

    std::string genate(std::string s)
    {
        std::string now;
        int j = 0;
        for(int i = 0; i < s.size(); i+= j)
        {
            for(j = 0; j + i < s.size(); ++j)
            {
                if(s[i] != s[i + j])
                {
                    break;
                }
            }
            now = now + int_to_string(j) + s[i];
        }
        return now;
    }

    std::string countAndSay(int n)
    {
        std::string s("1");

        while(--n)
        {
            s = genate(s);
        }
        return s;
    }
#endif
};
