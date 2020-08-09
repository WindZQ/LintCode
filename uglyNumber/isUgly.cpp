#define method1 1
#define method2 0


class Solution
{
public:
#if method1
    bool isUgly(int num)
    {
        while(num >= 2)
        {
            if(num % 2 == 0) num /= 2;
            else if(num % 3 == 0) num /= 3;
            else if(num % 5 == 0) num /= 5;
            else return false;
        }
        return num == 1;
    }
#endif

#if method2
    bool isUgly(int num)
    {
        if(num <= 0) return false;
        while(num % 2 == 0) num /= 2;
        while(num % 3 == 0) num /= 3;
        while(num % 5 == 0) num /= 5;
        return num == 1;
    }
#endif
};
