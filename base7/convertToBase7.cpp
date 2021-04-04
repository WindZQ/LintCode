#include <string>

#define method1 1
#define method2 0


class Solution
{
public:
#if method1
    std::string convertToBase7(int num)
    {
        if(num == 0) return "0";
        std::string res = "";
        bool positive = num > 0;
        while(num != 0)
        {
            res = std::to_string(std::abs(num % 7)) + res;
            num /= 7;
        }

        return positive ? res : "-" + res;
    }
#endif

#if method2
    std::string convertToBase7(int num)
    {
        if(num < 0) return "-" + convertToBase7(-num);
        if(num < 7) return std::to_string(num);
        return convertToBase7(num / 7) + std::to_string(num % 7);
    }
#endif
};
