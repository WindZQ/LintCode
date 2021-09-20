class Solution
{
public:
    int digitCounts(int k, int n)
    {
        int count = 0;
        if(k == 0)
        {
            count = 1;
        }

        for(int i = 1; i <= n; ++i)
        {
            int num = i;
            while(num > 0)
            {
                if(num % 10 == k)
                {
                    count += 1;
                }

                num /= 10;
            }
        }

        return count;
    }
};
