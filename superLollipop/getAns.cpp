#include <vector>
#include <algorithm>

class Soluton
{
public:
    int getAns(int v1, int v2, std::vector<int> &s, std::vector<int> &w)
    {
        int res = INT_MAX;
        if (v1 > v2) return 0;

        for (int i = 0; i < s.size(); ++i)
        {
            if (v1 + s[i] > v2)
            {
                res = std::min(res, w[i]);
            }
        }

        return res;
    }
};
