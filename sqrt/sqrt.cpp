#include <iostream>
#include <cmath>

#define method1 0
#define method2 0
#define method3 0
#define method4 0
#define method5 1

class Solution
{
public:
#if method1
    int sqrt(int x)
    {
        float y = x;
        long i = *(long *) &y;
        i = 0x5f375a86 - (i >> 1);
        y = 1 / *(float *)&i;
        y = (y + x / y) / 2;
        y = (y + x / y) / 2;
        return abs(y);
    }
#endif

#if method2
    int sqrt(int x)
    {
        long long guess = x, improve = x / 2, error = 0;
        while(improve)
        {
            guess -= improve;
            error = guess * guess - x;
            improve = error / 2 / guess;
        }

        return error > 0 ? --guess : guess;
    }
#endif

#if method3
    int sqrt(int x)
    {
        if(x <= 1) return x;
        int left = 0, right = x;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(x / mid >= mid)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return right - 1;
    }
#endif

#if method4
	int sqrt(int x)
	{
		if(x == 0) return 0;
		double res = 1, pre = 0;
		while(abs(res - pre) > 1e-6)
		{
			pre = res;
			res = (res + x / res) / 2;
		}
		return (int)res;
	}
#endif

#if method5
	int sqrt(int x)
	{
		long res = x;
		while(res * res > x)
		{
			res = (res + x / res) / 2;
		}
		return res;
	}
#endif
};

int main(void)
{
	Solution s;
	int x = 0;
	printf("Please input the number:");
	scanf("%d", &x);
	printf("The result is %d", s.sqrt(x));
	return 0;
}