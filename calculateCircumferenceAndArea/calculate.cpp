#include <vector>

class Solution
{
public:
    std::vector<double> calculate(int r)
    {
        std::vector<double> ans;
        ans.push_back(2 * 3.14 * r);
        ans.push_back(3.14 * r * r);
        return ans;
    }
};
