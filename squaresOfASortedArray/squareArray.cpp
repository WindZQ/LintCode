#include <vector>
#include <algorithm>

#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
    std::vector<int> squareArray(std::vector<int> &a)
    {
        std::vector<int> res;
        for (int num : a)
        {
            res.push_back(num * num);
        }

        std::sort(res.begin(), res.end());

        return res;
    }
#endif

#if method2
    std::vector<int> squareArray(std::vector<int> &a)
    {
        int n = a.size();
        int negative = -1;

        for (int i = 0; i < n; ++i)
        {
            if (a[i] < 0)
            {
                negative = i;
            }
            else
            {
                break;
            }
        }

        std::vector<int> res;
        int i = negative, j = negative + 1;

        while (i >= 0 || j < n)
        {
            if (i < 0)
            {
                res.push_back(a[j] * a[j]);
                ++j;
            }
            else if (j == n)
            {
                res.push_back(a[i] * a[i]);
                --i;
            }
            else if (a[i] * a[i] < a[j] * a[j])
            {
                res.push_back(a[i] * a[i]);
                --i;
            }
            else
            {
                res.push_back(a[j] * a[j]);
                ++j;
            }
        }

        return res;
    }
#endif

#if method3
    std::vector<int> squareArray(std::vector<int> &a)
    {
        int n = a.size();
        std::vector<int> res(n);

        for (int i = 0, j = n - 1, pos = n - 1; i <= j;)
        {
            if (a[i] * a[i] > a[j] * a[j])
            {
                res[pos] = a[i] * a[i];
                ++i;
            }
            else
            {
                res[pos] = a[j] * a[j];
                --j;
            }
            --pos;
        }

        return res;
    }
#endif
}
