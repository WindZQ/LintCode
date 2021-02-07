#include <string>
#include <vector>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    int countPalindromicSubstrings(std::string &str)
    {
        if(str.empty()) return 0;
        int n = str.size(), res = 0;
        for(int i = 0; i < n; ++i)
        {
            helper(str, i, i, res);
            helper(str, i, i + 1, res);
        }

        return res;
    }

    void helper(std::string s, int i, int j, int &res)
    {
        while(i >= 0 && j < s.size() && s[i] == s[j])
        {
            --i;
            ++j;
            ++res;
        }
    }
#endif

#if method2
    int countPalindromicSubstrings(std::string &str)
    {
        int n = str.size(), res = 0;
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n));

        for(int i = n - 1; i >= 0; --i)
        {
            for(int j = i; j < n; ++j)
            {
                dp[i][j] = (str[i] == str[j]) && (j - i <= 2 || dp[i + 1][j - 1]);
                if(dp[i][j]) ++res;
            }
        }

        return res;
    }
#endif
};
