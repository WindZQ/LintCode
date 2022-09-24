#include <string>


#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
    std::string rotateString2(std::string &str, int left, int right)
    {
        if (str.size() == 0) return str;

        std::string res;
        int len = str.size();
        int offset = (left - right) % len;

        if (offset >= 0)
        {
            std::string right_str = str.substr(offset, len - offset);
            std::string left_str = str.substr(0, offset);
            res = right_str + left_str;
        }
        else
        {
            offset = std::abs(offset);
            std::string left_str = str.substr(0, len - offset);
            std::string right_str = str.substr(len - offset, offset);
            res = right_str + left_str;
        }

        return res;
    }
#endif

#if method2
    std::string rotateString2(std::string &str, int left, int right)
    {
        int n = str.size();
        if (n <= 1) return str;

        int total = (right - left) % n;
        total = (total + n) % n;

        return str.substr(n - total) + str.substr(0, n - total);
    }
#endif

#if method3
    std::string rotateString2(std::string &str, int left, int right)
    {
        int n = str.size();
        left = (left % n - right % n + n) % n;

        return str.substr(left) + str.substr(0, left);
    }
#endif
}
