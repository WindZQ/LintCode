#include <string>
#include <unordered_set>

class Solution
{
public:
    std::string toGoatLatin(std::string &s)
    {
        std::unordered_set<char> vowel({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        std::istringstream iss(s);
        std::string res, w;
        int i = 0, j;

        while (iss >> w)
        {
            res += ' ' + (vowel.count(w[0]) == 1 ? w : w.substr(1) + w[0]) + "ma";

            for (j = 0, ++i; j < i; ++j)
            {
                res += "a";
            }
        }

        return res.substr(1);
    }
};
