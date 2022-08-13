#include <string>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<std::string> uncommonFromSentences(std::string &a, std::string &b)
    {
        std::unordered_map<std::string, int> m;
        std::stringstream ss;
        ss << a << " " << b;
        std::string s;
        while (ss >> s) ++m[std::move(s)];
        std::vector<std::string> res;
        for (auto && [s, c] : m)
        {
            if (c == 1)
            {
                res.emplace_back(std::move(s));
            }
        }

        return res;
    }
};
