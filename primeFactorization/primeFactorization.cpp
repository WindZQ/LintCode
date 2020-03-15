#include <iostream>
#include <vector>
#include <cmath>

#define method1 1
#define method2 0


class Solution
{
public:
    std::vector<int> primeFactorization(int num)
    {
        if(num <= 0)
        {
            return std::vector<int>();
        }

        std::vector<int> result;
        int up = sqrt(num);
        for(int i = 2; i <= up; ++i)
        {
            if(num == 1)
            {
                return result;
            }
            while((num % i) == 0)
            {
                result.push_back(i);
                num /= i;
            }
        }

        if(num > 1)
        {
            result.push_back(num);
        }
        return result;
    }
};
