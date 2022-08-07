#include <string>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    bool canConvert(std::string &s, std::string &t)
    {
        int index_s = 0, index_t = 0;
        for (index_s = 0; index_s < s.size(); index_s++)
        {
            if (s[index_s] == t[index_t])
            {
                index_t++;
                if (index_t == t.size()) return true;
            }
        }

        return false;
    }
#endif

#if method2
    bool canConvert(std::string &s, std::string &t)
    {
        int left = 0, right = 0;

        while (left < s.size())
        {
            if (s[left] == t[right])
            {
                right += 1;
            }

            left += 1;
        }

        if (right == t.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
#endif
};
