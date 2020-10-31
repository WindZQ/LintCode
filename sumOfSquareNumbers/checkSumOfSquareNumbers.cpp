#include <math>
#include <unordered_set>

#define method1 1
#define method2 0
#define method3 0
#define method4 0

class Solution
{
public:
#if method1
    bool checkSumOfSquareNumbers(int num)
    {
        for(int i = sqrt(num); i >= 0; --i)
        {
            if(i * i == num) return true;
            int d = num - i * i, t= sqrt(d);
            if(t * t == d) return true;
        }
        return false;
    }
#endif

#if method2
    bool checkSumOfSquareNumbers(int num)
    {
        std::unordered_set<int> s;
        for(int i = 0; i <= sqrt(num); ++i)
        {
            s.insert(i * i);
            if(s.count(num - i * i)) return true;
        }
        return false;
    }
#endif

#if method3
    bool checkSumOfSquareNumbers(int num)
    {
        long a = 0, b = sqrt(num);
        while(a <= b)
        {
            if(a * a + b * b == num) return true;
            else if(a * a + b * b < num) ++a;
            else --b;
        }
        return false;
    }
#endif

#if method4
    bool checkSumOfSquareNumbers(int num)
    {
        if(num < 0) return false;

        for(int i = 2; i * i <= num; ++i)
        {
            if(num % i != 0) continue;
            int cnt = 0;
            while(num % i == 0)
            {
                ++cnt;
                num /= i;
            }
            if(i % 4 == 3 && cnt % 2 != 0) return false;
        }
        return num % 4 != 3;
    }
#endif
};
