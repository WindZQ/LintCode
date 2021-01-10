#include <math>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    int reachNumber(int target)
    {
        target = std::abs(target);
        long n = ceil((-1.0 + std::sqrt(1 + 8.0 * target)) / 2);
        long sum = n * (n + 1) / 2;
        if(sum == target) return n;
        long res = sum - target;
        if((res & 1) == 0) return n;
        return n + ((n & 1) ? 2 : 1);
    }
#endif

#if method2
    int reachNumber(int target)
    {
        target = std::abs(target);
        int res = 0, sum = 0;
        while(sum < target || (sum - target) % 2 == 1)
        {
            ++res;
            sum += res;
        }
        return res;
    }
#endif
};
