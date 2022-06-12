#include <vector>
#include <string>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    std::vector<std::vector<int>> largeGroupPositions(std::string &s)
    {
        std::vector<std::vector<int>> res;
        int n = s.size(), i = 0, j = 0;

        while (j < n)
        {
            while (j < n && s[j] == s[i]) ++j;
            if (j - i >= 3) res.push_back({i, j - 1});
            i = j;
        }

        return res;
    }
#endif

#if method2
    std::vector<std::vector<int>> largeGroupPositions(std::string &s)
    {
        std::vector<std::vector<int>> res;
        int n = s.size(), start = 0;

        for (int i = 1; i <= n; ++i)
        {
            if (i < n && s[i] == s[start]) continue;
            if (i - start >= 3) res.push_back({start, i - 1});
            start = i;
        }

        return res;
    }
#endif
};
