#include <vector>

class Solution
{
public:
    std::vector<int> calculateNumber(int num)
    {
        std::vector<int> res;
        int a[1050], sum = 0, l = 0;

        while (num > 0)
        {
            if (num % 2 == 1) sum++;

            a[l] = num % 2;
            num /= 2;
            l++;
        }

        res.push_back(sum);
        for (int i = l - 1; i >= 0; --i)
        {
            if (a[i]) res.push_back(l - i);
        }

        return res;
    }
};
