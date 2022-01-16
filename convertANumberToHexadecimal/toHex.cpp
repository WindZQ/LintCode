#include <string>
#include <iostream>
#include <vector>
#include <math>

#define method1 1
#define method2 0
#define method3 0
#define method4 0

class Solution
{
public:
#if method1
    std::string toHex(int num)
    {
        std::string res = "";
        std::vector<std::string> v {"a", "b", "c", "d", "e", "f"};
        int n = 7;
        unsigned int x = num;
        if(num < 0) x = UINT_MAX + num + 1;
        while(x > 0)
        {
            int t = pow(16, n);
            int d = x / t;
            if(d >= 10) res += v[d - 10];
            else if(d >= 0)
            {
                res += to_string(d);
            }
            x %= t;
            --n;
        }
        while(n-- >= 0) res += to_string(0);
        while(!res.empty() && res[0] == '0') res.erase(res.begin());
        return res.empty() ? "0" : res;
    }
#endif

#if method2
    std::string toHex(int num)
    {
        std::string res = "";
        for(int i = 0; num && i < 8; ++i)
        {
            int t = num & 0xf;
            if(t >= 10)
            {
                res = char('a' + t - 10) + res;
            }
            else
            {
                res = char('0' + t) + res;
            }
            num >>= 4;
        }
        return res.empty() ? "0" : res;
    }
#endif

#if method3
    std::string toHex(int num)
    {
        std::string res = "", str = "0123456789abcdef";
        int cnt = 0;
        while(num != 0 && cnt++ < 8)
        {
            res = str[(num & 0xf)] + res;
            num >>= 4;
        }

        return res.empty() ? "0" : res;
    }
#endif

#if method4
    std::string toHex(int num)
    {
        std::ostringstream ios;
        ios << hex << num;
        return ios.str();
    }
#endif
};
