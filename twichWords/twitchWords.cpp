#include <vector>
#include <string>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    std::vector<std::vector<int>> twitchWords(std::string &str)
    {
        std::vector<std::vector<int>> res;
        int start = 0, end = 0;

        for (int i = 1; i < str.length(); ++i)
        {
            if (str[i] == str[i - 1])
            {
                end++;
            }
            else
            {
                if (end - start + 1 >= 3)
                {
                    add(start, end, res);
                }

                start = end = i;
            }
        }

        if (end - start + 1 >= 3)
        {
            add(start, end, res);
        }

        return res;
    }

    void add(int start, int end, std::vector<std::vector<int>> &res)
    {
        std::vector<int> temp;
        temp.push_back(start);
        temp.push_back(end);
        res.push_back(temp);
    }
#endif

#if method2
    std::vector<std::vector<int>> twitchWords(std::string &str)
    {
        int len = str.length(), l = 0, r = 1;
        std::vector<std::vector<int>> res;

        while (l < len - 1)
        {
            r = l + 1;
            while (r < len && str[l] == str[r])
            {
                r++;
            }

            if (r - l >= 3)
            {
                res.push_back({l, r - 1});
                l = r;
                continue;
            }
            l++;
        }

        return res;
    }
#endif
};
