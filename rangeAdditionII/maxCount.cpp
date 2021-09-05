#include <vector>
#include <queue>
#include <algorithm>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    int maxCount(int m, int n, std::vector<std::vector<int>> &ops)
    {
        if(ops.empty() || ops[0].empty()) return m * n;
        std::priority_queue<int> r, c;

        for(auto op : ops)
        {
            r.push(-op[0]);
            c.push(-op[1]);
        }

        return r.top() * c.top();
    }
#endif

#if method2
    int maxCount(int m, int n, std::vector<std::vector<int>> &ops)
    {
        for(auto op : ops)
        {
            m = std::min(m, op[0]);
            n = std::min(n, op[1]);
        }

        return m * n;
    }
#endif
};
