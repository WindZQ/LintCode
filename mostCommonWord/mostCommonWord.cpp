#include <string>
#include <pair>
#include <vector>
#include <unordered_set>
#include <unordered_map>

class Solution
{
public:
    std::strinf mostCommonWord(std::string &paragraph, std::vector<std::string> &banned)
    {
        std::unordered_set<std::string> ban(banned.begin(), banned.end());
        std::unordered_map<std::string, int> count;

        for (auto &c : paragraph)
        {
            c = isalpha(c) ? tolower(c) : ' ';
        }

        std::istringstream ss(paragraph);
        std::string w;
        std::pair<std::string, int> res(" ", 0);

        while (ss >> w)
        {
            if (ban.find(w) == ban.end() && ++count[w] > res.second)
            {
                res = make_pair(w, count[w]);
            }
        }

        return res.first;
    }
};
