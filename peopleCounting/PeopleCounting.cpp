#include <vector>
#include <map>

class Solution
{
public:
    std::vector<int> PeopleCounting(std::vector<int> &wage, std::vector<int> &ask)
    {
        std::map<int, int> m;
        for(int k : wage)
        {
            m[k]++;
        }

        std::vector<int> res;
        for(int k : ask)
        {
            res.push_back(m[k]);
        }

        return res;
    }
};
