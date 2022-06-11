#include <string>


#define method1 1
#define method2 0


class Solution
{
public:
#if method1
    bool backspaceCompare(std::string &s, std::string &t)
    {
        return build(s) == build(t);
    }

    std::string build(std::string str)
    {
        std::string res;

        for (char ch : str)
        {
            if (ch != '#')
            {
                res.push_back(ch);
            }
            else if (!res.empty())
            {
                res.pop_back();
            }
        }

        return res;
    }
#endif

#if method2
    bool backspaceCompare(std::string &s, std::string &t)
    {
        int i = s.length() - 1, j = t.length() - 1;
        int skip_s = 0, skip_t = 0;

        while (i >= 0 || j >= 0)
        {
            while (i >= 0)
            {
                if (s[i] == '#')
                {
                    skip_s++;
                    i--;
                }
                else if (skip_s > 0)
                {
                    skip_s--;
                    i--;
                }
                else
                {
                    break;
                }
            }

            while (j >= 0)
            {
                if (t[j] == '#')
                {
                    skip_t++;
                    j--;
                }
                else if (skip_t > 0)
                {
                    skip_t--;
                    j--;
                }
                else
                {
                    break;
                }
            }

            if (i >= 0 && j >= 0)
            {
                if (s[i] != t[j])
                {
                    return false;
                }
            }
            else
            {
                if (i >= 0 || j >= 0)
                {
                    return false;
                }
            }

            i--;
            j--;
        }

        return true;
    }
#endif
};
