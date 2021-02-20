#include <math>

#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
    int gcd(int a, int b)
    {
        int divisor = a, numerator = b;
        if(a == b) return a;
        if(a > b) divisor = b, numerator = a;

        while(numerator % divisor != 0)
        {
            int tmp = numerator % divisor;
            numerator = divisor;
            divisor = tmp;
        }

        return divisor;
    }
#endif

#if method2
    int gcd(int a, int b)
    {
        if(a == b) return a;
        int m = std::min(a, b);

        for(int i = m; m > 1; --m)
        {
            if(a % m == 0 && b % m == 0) return m;
        }
    }
#endif

#if method3
    int gcd(int a, int b)
    {
        if(b == 0) return a;
        return gcd(b, a % b);
    }
#endif
};
