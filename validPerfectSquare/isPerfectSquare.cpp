#include <math>

#define method1 1
#define method2 0
#define method3 0
#define method4 0
#define method5 0

class Solution
{
public:
#if method1
    bool isPerfectSquare(int num)
    {
        if(num == 1) return true;
        long x = num / 2, t = x * x;
        while(t > num)
        {
            x /= 2;
            t = x * x;
        }

        for(int i = x; i <= 2 * x; ++i)
        {
            if(i * i == num) return true;
        }

        return false;
    }
#endif

#if method2
    bool isPerfectSquare(int num)
    {
        for(int i = 1; i <= num / i; ++i)
        {
            if(i * i == num) return true;
        }

        return false;
    }
#endif

#if method3
    bool isPerfectSquare(int num)
    {
        long left = 0, right = num;
        while(left <= right)
        {
            long mid = left + (right - left) / 2, t = mid * mid;
            if(t == num) return true;
            if(t < num) left = mid + 1;
            else
                right = mid + 1;
        }

        return false;
    }
#endif

#if method4
    bool isPerfectSquare(int num)
    {
        int i = 1;
        while(num > 0)
        {
            num -= i;
            i += 2;
        }

        return num == 0;
    }
#endif

#if method5
    bool isPerfectSquare(int num)
    {
        long x = num;
        while(x * x > num)
        {
            x = (x + num / x) / 2;
        }

        return x * x == num;
    }
#endif
};
