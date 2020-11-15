#include <string>

#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
    std::string isBuild(int x)
    {
        if(helper(x))
        {
            return "YES";
        }
        else
        {
            return "NO";
        }
    }

    bool helper(int x)
    {
        if(x == 0) return true;
        if(x < 0) return false;
        return helper(x - 3) || helper(x - 7);
    }
#endif

#if method2
    std::string isBuild(int x)
    {
        int tags[6] = {1, 2, 4, 5, 8, 11};
        for(int i = 0; i< 6; ++i)
        {
            if(x == tags[i])
            {
                return "NO";
            }
        }

        return "YES";
    }
#endif

#if method3
    std::string isBuild(int x)
    {
        if(x > 12 || x == 3)
        {
            return "YES";
        }
        else
        {
            int y = x % 7 % 3;
            if((y == 0) && (x >= 7 || y == 2))
            {
                return "YES";
            }
            return "NO";
        }
    }
#endif
};
