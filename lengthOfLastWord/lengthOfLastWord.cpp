#include <string>

#define method1 1
#define method2 0
#define method3 0
#define method4 0

class Solution
{
public:
#if method1
    int lengthOfLastWord(std::string s)
    {
        int length = 0;
        for(int i = s.length() - 1; i >= 0; --i)
        {
            if(length == 0)
            {
                if(s[i] == ' ')
                {
                    continue;
                }
                else
                {
                    length++;
                }
            }
            else
            {
                if(s[i] == ' ')
                {
                    break;
                }
                else
                {
                    length++;
                }
            }
        }
        return length;
    }
#endif

#if method2
    int lengthOfLastWord(std::string s)
    {
        int left = 0, right = (int)s.size() - 1, res = 0;
        while(s[left] == ' ') ++left;
        while(s[right] == ' ') --right;

        for(int i = left; i <= right; ++i)
        {
            if(s[i] == ' ')
            {
                res = 0;
            }
            else
            {
                ++res;
            }
        }

        return res;
    }
#endif

#if method3
    int lengthOfLastWord(std::string s)
    {
        int res = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] != ' ')
            {
                if(i != 0 && s[i - 1] == ' ')
                {
                    res = 1;
                }
                else
                {
                    ++res;
                }
            }
        }

        return res;
    }
#endif

#if method4
    int lengthOfLastWord(std::string s)
    {
        int right = s.size() - 1, res = 0;

        while(right >= 0 && s[right] == ' ') --right;
        while(right >= 0 && s[right] != ' ')
        {
            --right;
            ++res;
        }

        return res;
    }
#endif
};
