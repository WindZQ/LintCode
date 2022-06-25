#include <string>
#include <vector>
#include <map>
#include <pair>
#include <algorithm>

class Solution
{
public:
    double maximumAverageScore(std::vector<std::string> &names, std::vector<int> &grades)
    {
        std::map<std::string, std::pair<int, int>> m;

        for (int i = 0; i < names.size(); ++i)
        {
            m[names[i]].first += grades[i];
            m[names[i]].second++;
        }

        double res = -1.0;

        for (auto p : m)
        {
            double avg = p.second.first * 1.0 / p.second.second;
            res = std::max(res, avg);
        }

        return res;
    }
};
