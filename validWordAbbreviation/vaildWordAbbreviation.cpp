#include <string>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    bool vaildWordAbbreviation(std::string &word, std::string &abbr)
    {
        int i = 0, j = 0, m = word.size(), n = abbr.size();
        while(i < m && j < n)
        {
            if(abbr[j] >= '0' && abbr[j] <= '9')
            {
                if(abbr[j] == '0') return false;
                int val = 0;
                while(j < n && abbr[j] >= '0' && abbr[j] <= '9')
                {
                    val = val * 10 + abbr[j++] - '0';
                }
                i += val;
            }
            else
            {
                if(word[i++] != abbr[j++]) return false;
            }
        }
        return i == m && j == n;
    }
#endif

#if method2
    bool vaildWordAbbreviation(std::string &word, std::string &abbr)
    {
        int m = word.size(), n = abbr.size(), p = 0, cnt = 0;
        for(int i = 0; i < abbr.size(); ++i)
        {
            if(abbr[i] >= '0' && abbr[i] <= '9')
            {
                if(cnt == 0 && abbr[i] == '0') return false;
                cnt = 10 * cnt + abbr[i] - '0';
            }
            else
            {
                p += cnt;
                if(p >= m || word[p++] != abbr[i]) return false;
                cnt = 0;
            }
        }
        return p + cnt == m;
    }
#endif
}
