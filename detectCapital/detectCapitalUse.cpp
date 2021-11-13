#include <string>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    bool detectCapitalUse(std::string &word)
    {
        int cnt = 0, n = word.size();
        for(int i = 0; i < n; ++i)
        {
            if(word[i] <= 'Z') ++cnt;
        }

        return cnt == 0 || cnt == n || (cnt == 1 && word[0] <= 'Z');
    }
#endif

#if method2
    bool detectCapitalUse(std::string &word)
    {
        int cnt = std::count_if(word.begin(), word.end(), [](char c){ return c <= 'Z';});
        return cnt == 0 || cnt == word.size() || (cnt == 1 && word[0] <= 'Z');
    }
#endif
};
