#include <string>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    std::string hexConversion(int n, int k)
    {
        std::string res;
        if(n == 0)
        {
            return "0";
        }

        while(n > 0)
        {
            int t = n % k;
            char c = ' ';
            if(t <= 9)
            {
                c = '0' + t;
            }
            else
            {
                c = 'A' + t - 10;
            }

            res = c + res;
            n /= k;
        }
        return res;
    }
#endif

#if method2
    std::string dict = "0123456789ABCDEF";
    std::string hexConversion(int n, int k)
    {
        if(n == 0) return "0";
        return helper(n, k);
    }

    std::string helper(int n, int k)
    {
        if(n == 0) return "";
        return helper(n / k, k) + dict[n % k];
    }
#endif
};
