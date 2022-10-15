#include <vector>
#include <multimap>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    char longestLightingTime(std::vector<std::vector<int>> &operation)
    {
        int max_time = operation[0][1];
        char res = 'a' + operation[0][0];
        int n = operation.size();

        for (int i = 0; i < n - 1; ++i)
        {
            std::vector<int> next = operation[i + 1];
            std::vector<int> current = operation[i];
            int time = next[1] - current[1];
            if (time > max_time)
            {
                max_time = time;
                res = next[0] + 'a';
            }
        }

        return res;
    }
#endif

#if method2
    char longestLightingTime(std::vector<std::vector<int>> &operation)
    {
        std::multimap<int, int, greater<int>> hash;
        int current = 0;
        int m = operation.size();

        for (int i = 0; i < m; ++i)
        {
            int dist = operation[i][1] - current;
            hash.insert({dist, operation[i][0]});
            current = operation[i][1];
        }

        auto res = hash.begin();

        return res->second + 'a';
    }
#endif
};
