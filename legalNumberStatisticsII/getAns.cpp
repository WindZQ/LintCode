#include <vector>

class Solution
{
public:
    std::vector<int> getAns(std::vector<int> &a, std::vector<std::vector<int>> &q)
    {
        std::vector<int> res;
        int n = a.size(), m = q.size();

        for (int j = 0; j < m; ++j)
        {
            int L = q[j][0], R = q[j][1];
            int ans = 0;

            for (int i = 0; i < n; ++i)
            {
                if (a[i] >= L && a[i] <= R)
                {
                    ans++;
                }
            }

            res.push_back(ans);
        }

        return res;
    }
};
