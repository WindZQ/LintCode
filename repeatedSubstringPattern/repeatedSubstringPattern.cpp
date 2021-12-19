#include <string>
#include <vector>

#define method1 1
#define method2 0
#define method3 0
#define method4 0

class Solution
{
public:
#if method1
    bool repeatedSubstringPattern(std::string &s)
    {
        int n = s.size();
        for(int i = n / 2; i >= 1; --i)
        {
            if(n % i == 0)
            {
                int c = n / i;
                std::string t = "";
                for(int j = 0; j < c; ++j)
                {
                    t += s.substr(0, i);
                }

                if(t == s) return true;
            }
        }

        return false;
    }
#endif

#if method2
    bool repeatedSubstringPattern(std::string &s)
    {
        return (s + s).find(s, 1) != s.size();
    }
#endif

#if method3
    bool kmp(const string &query, const string &pattern)
    {
        int n = query.size();
        int m = pattern.size();
        std::vector<int> fail(m, -1);

        for(int i = 1; i < m; ++i)
        {
            int j = fail[i - 1];
            while(j != -1 && pattern[j + 1] != pattern[i])
            {
                j = fail[j];
            }

            if(pattern[j + 1] == pattern[i])
            {
                fail[i] = j + 1;
            }
        }

        int match = -1;
        for(int i = 1; i < n - 1; ++i)
        {
            while(match != -1 && pattern[match + 1] != query[i])
            {
                match = fail[match];
            }

            if(pattern[match + 1] == query[i])
            {
                ++match;
                if(match == m - 1) return true;
            }
        }

        return false;
    }

    bool repeatedSubstringPattern(std::string &s)
    {
        return kmp(s + s, s);
    }
#endif

#if method4
    bool repeatedSubstringPattern(std::string &s)
    {
        int i = 1, j = 0, n = s.size();
        std::vector<int> dp(n + 1, 0);

        while(i < n)
        {
            if(s[i] == s[j]) dp[++i] = ++j;
            else if(j == 0) ++i;
            else j = dp[j];
        }

        return dp[n] && (dp[n] % (n - dp[n]) == 0);
    }
#endif
};
