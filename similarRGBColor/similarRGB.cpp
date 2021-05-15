#include <string>

#define method1 1
#define method2 0


class Solution
{
public:
#if method1
    std::string similarRGB(std::string &color)
    {
        return "#" + helper(color.substr(1, 2)) + helper(color.substr(3, 2)) + helper(color.substr(5, 2));
    }

    std::string helper(std::string str)
    {
        std::string dict = "0123456789abcdef";
        int num = stoi(str, nullptr, 16);
        int index = num / 17 + (num % 17 > 8 ? 1 : 0);
        return string(2, dict[index]);
    }

#endif

#if method2
    std::string similarRGB(std::string &color)
    {
        for(int i = 1; i < color.size(); i += 2)
        {
            int num = stoi(color.substr(i, 2), nullptr, 16);
            int index = num / 17 + (num % 17 > 8 ? 1 : 0);
            color[i] = color[i + 1] = (index > 9) ? (index - 10 + 'a') : (index + '0');
        }

        return color;
    }
#endif
};
