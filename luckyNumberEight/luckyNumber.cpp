
class Solution
{
public:
    int luckyNumber(int n)
    {
        int res = 0;

        for (int i = 0; i < n; ++i)
        {
            res += check(i);
        }

        return res;
    }

    int check(int n)
    {
        while (n)
        {
            if (n % 10 == 8) return 1;

            n /= 10;
        }

        return 0;
    }
};
