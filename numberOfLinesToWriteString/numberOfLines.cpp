#include <vector>
#include <string>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    std::vector<int> numberOfLines(std::vector<int> &widths, std::string &S)
    {
        int cnt = 1, cur = 0;
        for(char c : S)
        {
            int t = widths[c - 'a'];
            if(cur + t > 100) ++cnt;
            cur = (cur + t > 100) ? t : cur + t;
        }

        return {cnt, cur};
    }
#endif

#if method2
    std::vector<int> numberOfLines(std::vector<int> &widths, std::string &S)
    {
        int lines = 1, last_length = 0, index = 0, len = S.size();
        for(int i = 0; i < len; ++i)
        {
            index = S[i] - 'a';
            last_length += widths[index];
            if(last_length > 100)
            {
                lines++;
                last_length = widths[index];
            }
        }

        std::vector<int> res;
        res.push_back(lines);
        res.push_back(last_length);

        return res;
    }
#endif
};
