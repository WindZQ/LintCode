#include <string>
#include <vector>

class Solution
{
public:
    std::vector<int> diStringMatch(std::string &s)
    {
        std::vector<int> res;
        int n = s.size(), mn = 0, mx = n;

        for (char c : s)
        {
            if (c == 'I')
            {
                res.push_back(mn++);
            }
            else
            {
                res.push_back(mx--);
            }
        }
        res.push_back(mx);

        return res;
    }
};
