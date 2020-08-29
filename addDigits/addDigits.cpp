#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    int addDigits(int num)
    {
        while(num / 10 > 0)
        {
            int sum = 0;
            while(num > 0)
            {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }

        return num;
    }
#endif

#if method2
    int addDigits(int num)
    {
        return (num == 0) ? 0 : (num - 1) % 9 + 1;
    }
#endif
};
