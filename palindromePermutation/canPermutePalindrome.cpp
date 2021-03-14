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
    bool canPermutePalindrome(std::string &s)
    {
        int res = 0, counts[256] = {0};

        for(char c : s)
        {
            res += ++counts[c] & 1 ? 1 : -1;
        }

        return res <= 1;
    }
#endif

#if method2
    bool canPermutePalindrome(std::string &s)
    {
        std::unordered_map<char, int> m;
        int res = 0;
        for(auto a : s) ++m[a];
        for(auto a : m)
        {
            if(a.second % 2 == 1) ++res;
        }

        return res == 0 || (s.size() % 2 == 1 && res == 1);
    }
#endif

#if method3
    bool canPermutePalindrome(std::string &s)
    {
        std::unordered_set<char> st;
        for(auto a : s)
        {
            if(!st.count(a))
            {
                st.insert(a);
            }
            else
            {
                st.erase(a);
            }
        }

        return st.empty() || st.size() == 1;
    }
#endif
};
