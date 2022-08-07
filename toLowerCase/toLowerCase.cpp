#include <string>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    std::string toLowerCase(std::string str)
    {
        for (char &ch : str)
        {
            ch = tolower(ch);
        }

        return str;
    }
#endif

#if method2
    std::string toLowerCase(std::string str)
    {
        for (char &ch : str)
        {
            if (ch >= 65 && ch <= 90)
            {
                ch |= 32;
            }
        }

        return str;
    }
#endif
};
