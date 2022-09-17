#include <vector>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    bool isMonotonic(std::vector<int> &a)
    {
        bool inc = true, dec = true;

        for (int i = 1; i < a.size(); ++i)
        {
            inc &= (a[i - 1] <= a[i]);
            dec &= (a[i - 1] >= a[i]);

            if (!inc && !dec) return false;
        }

        return true;
    }
#endif

#if method2
    bool isMonotonic(std::vector<int> &a)
    {
        int inc = 1, dec = 1, n = a.size();

        for (int i = 1; i < n; ++i)
        {
            inc += (a[i - 1] <= a[i]);
            dec += (a[i - 1] >= a[i]);
        }

        return (inc == n) || (dec == n);
    }
#endif
};
