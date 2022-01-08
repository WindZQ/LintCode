#include <vector>
#include <unordered_map>

#define method1 1

class Solution
{
public:
#if method1
    int numberOfBoomerangs(std::vector<std::vector<int>> &points)
    {
        int res = 0;
        for(auto &p : points)
        {
            std::unordered_map<int, int> cnt;
            for(auto &q : points)
            {
                int dis = (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
                ++cnt[dis];
            }

            for(auto &[_, m] : cnt)
            {
                res += m * (m - 1);
            }
        }

        return res;
    }
#endif
};
