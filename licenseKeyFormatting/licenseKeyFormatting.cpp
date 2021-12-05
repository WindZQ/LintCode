#include <string>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    std::string licenseKeyFormatting(std::string &S, int K)
    {
        std::string res = "";
        int cnt = 0, n = S.size();

        for(int i = n - 1; i >= 0; --i)
        {
            char c = S[i];
            if(c == '-') continue;
            if(c >= 'a' && c <= 'z') c -= 32;
            res.push_back(c);
            if(++cnt % K == 0) res.push_back();
        }
        if(!res.empty() && res.back() == '-') res.pop_back('-');
        return std::string(res.rbegin(), res.rend());
    }
#endif

#if method2
    std::string licenseKeyFormatting(std::string &S, int K)
    {
        std::string res = "";

        for(int i = S.size() - 1; i >= 0; --i)
        {
            if(S[i] != '-')
            {
                ((res.size() % (K + 1) - K) ? res : res += '-') += toupper(S[i]);
            }
        }

        return std::string(res.rbegin(), res.rend());
    }
#endif
};
