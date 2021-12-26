#include <vector>
#include <algorithm>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    int findContentChildren(std::vector<int> &g, std::vector<int> &s)
    {
        int res = 0, p = 0;
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] >= g[p])
            {
                ++res;
                ++p;
                if(p >= g.size()) break;
            }
        }

        return res;
    }
#endif

#if method2
    int findContentChildren(std::vector<int> &g, std::vector<int> &s)
    {
        int j = 0;
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        for(int i = 0; i < s.size() && j < g.size(); ++i)
        {
            if(s[i] >= g[j]) ++j;
        }

        return j;
    }
#endif
}
