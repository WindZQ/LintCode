#include <vector>

#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
    bool checkPerfectNumber(int num)
    {
        if(num <= 1) return false;
        int sum = 1, i = 2;
        for(; i * i < num; ++i)
        {
            if(num % i == 0)
            {
                sum += i + num / i;
            }
        }

        if(i * i == num) sum += i;
        return sum == num;
    }
#endif

#if method2
    bool checkPerfectNumber(int num)
    {
        std::vector<int> p{2, 3, 5, 7, 13};
        int temp = 2;
        std::vector<int> ans{6};

        for(int i = 1; i < 5; ++i)
        {
            int diff = p[i] - p[i - 1];
            while(diff--) { temp <<= 1;}
            ans.emplace_back(temp * ((temp << 1) - 1));
        }

        for(int a : ans)
        {
            if(a == num) return true;
        }

        return false;
    }
#endif

#if method3
    bool checkPerfectNumber(int num)
    {
        return num == 6 || num == 28 || num == 496 || num == 8128 || num == 33550336;
    }
#endif
};
