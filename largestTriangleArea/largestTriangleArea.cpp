#include <vector>
#include <cmath>
#include <algorithm>

#define method1 1
#define method2 0


class Solution
{
public:
#if method1
    double largestTriangleArea(std::vector<std::vector<int>> &points)
    {
        double res = 0;
        for(int i = 0; i < points.size(); ++i)
        {
            for(int j = i + 1; j < points.size(); ++j)
            {
                for(int k = j + 1; k < points.size();++k)
                {
                    int x1 = points[i][0], y1 = points[i][1];
                    int x2 = points[j][0], y2 = points[j][1];
                    int x3 = points[k][0], y3 = points[k][1];
                    double area = std::abs(0.5 * (x2 * y3 + x1 * y2 + x3 * y1 - x3 * y2 - x2 * y1 - x1 * y3));
                    res = std::max(res, area);
                }
            }
        }

        return res;
    }
#endif

#if method2
    double largestTriangleArea(std::vector<std::vector<int>> &points)
    {
        double res = 0;
        for (auto &i : points)
        {
            for (auto &j : points)
            {
                for (auto &k : points)
                {
                    res = std::max(res, 0.5 * std::abs(i[0] * j[1] + j[0] * k[1] + k[0] * i[1]- j[0] * i[1] - k[0] * j[1] - i[0] * k[1]));
                }
            }
        }
        return res;
    }
#endif
};
