#include <vector>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    int peakIndexMountainArray(std::vector<int> &a)
    {
        for (int i = 1; i < a.size(); ++i)
        {
            if (a[i] > a[i + 1]) return i;
        }

        return 0;
    }
#endif

#if method2
    int peakIndexMountainArray(std::vector<int> &a)
    {
        int n = a.size(), left = 0, right = n - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (a[mid] < a[mid + 1])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return right;
    }
#endif
};
