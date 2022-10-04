
class Solution
{
public:
    long long rotatedNums(int n)
    {
        long long res = 1;

        if (n == 1) return 5;
        if (n == 2) return 6;

        if (n % 2 == 1)
        {
            for (int i = 0; i < n / 2; ++i)
            {
                if (i == 0)
                {
                    res *= 6;
                }
                else
                {
                    res *= 7;
                }
            }

            res *= 5;
        }
        else
        {
            for (int i = 0; i < n / 2; ++i)
            {
                if (i == 0)
                {
                    res *= 6;
                }
                else
                {
                    res *= 7;
                }
            }
        }

        return res;
    }
};
