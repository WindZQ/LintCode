#include <string>
#include <unordered_map>
#include <unordered_set>

#define method1 1
#define method2 0
#define method3 0


class Solution
{
public:
#if method1
    int longestPalindrome(std::string &s)
    {
        int res = 0;
        bool mid = false;
        std::unordered_map<char, int> m;
        for(char c : s) ++m[c];
        for(auto it = m.begin(); it != m.end(); ++it)
        {
            res += it->second;
            if(it->second % 2 == 1)
            {
                res -= 1;
                mid = true;
            }
        }
        return mid ? res + 1 : res;
    }
#endif

#if method2
    int longestPalindrome(std::string &s)
    {
        std::unordered_set<char> t;
        for(char c : s)
        {
            if(!t.count(c))
            {
                t.insert(c);
            }
            else
            {
                t.erase(c);
            }
        }
        return s.size() - std::max(0, (int)t.size() - 1);
    }
#endif

#if method3
    int longestPalindrome(std::string &s)
    {
        int odds = 0;
        for(char c = 'A'; c <= 'z'; ++c)
        {
            odds += std::count(s.begin(), s.end(), c) & 1;
        }
        return s.size() - std::max(0, odds - 1);
    }
#endif
};
