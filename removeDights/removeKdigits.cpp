#include <string>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    std::string removeKdigits(std::string &num, int k)
    {
        std::string res = "";
        int n = num.size(), keep = n - k;
        for(char c : num)
        {
            while(k && res.size() && res.back() > c)
            {
                res.pop_back();
                --k;
            }
            res.push_back(c);
        }

        res.resize(keep);
        while(!res.empty() && res[0] == '0') res.erase(res.begin());
        return res.empty() ? "0" : res;
    }
#endif

#if method2
    std::string removeKdigits(std::string &num, int k)
    {
        std::string res;
        int n = num.size(), keep = n - k;
        for(char c : num)
        {
            while(k && res.size() && res.back() > c)
            {
                res.pop_back();
                --k;
            }
            if(res.size() || c != '0') res.push_back(c);
        }

        while(res.size() && k--) res.pop_back();
        return res.empty() ? "0" : res;
    }
#endif
};
