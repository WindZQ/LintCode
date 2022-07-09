#include <string>
#include <vector>
#include <unordered_set>

class Solution
{
public:
    bool buddyStrings(std::string &a, std::string &b)
    {
        if (a.size() != b.size()) return false;
        if (a == b && std::unordered_set<char>(a.begin(), a.end()).size() < a.size())
            return true;

        std::vector<int> diff;
        for (int i = 0; i < a.size(); ++i)
        {
            if (a[i] != b[i]) diff.push_back(i);
        }

        return diff.size() == 2 && a[diff[0]] == b[diff[1]] && a[diff[1]] == b[diff[0]];
    }
};
