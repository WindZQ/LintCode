#include <vector>

class Solution
{
public:
    std::vector<int> largestSubarray(std::vector<int> &a, int k)
    {
        std::vector<int> res;
        int start = 0;

        for (int i = 0; i <= a.size() - k; ++i)
        {
            for (int j = 0; j < k; ++j)
            {
                if (a[i + j] > a[start + j])
                {
                    start = i;
                    break;
                }
                else if (a[i + j] < a[start + j])
                {
                    break;
                }
            }
        }

        for (int i = 0; i < k; ++i)
        {
            res.push_back(a[start + i]);
        }

        return res;
    }
};
