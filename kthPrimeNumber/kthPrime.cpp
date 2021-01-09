#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    int kthPrime(int n)
    {
        int num = 0;
        for(int i = 1; i < n; ++i)
        {
            bool isPrime = true;
            for(int j = 1; j < i; ++j)
            {
                if(j != 1 && i % j == 0)
                {
                    isPrime = false;
                    break;
                }
            }
            if(isPrime)
            {
                num++;
            }
        }

        return num;
    }
#endif

#if method2
    int kthPrime(int n)
    {
        bool prime[100009];
        memset(prime, false, sizeof(prime));

        for(int i = 2; i < n; ++i)
        {
            if(prime[i] == 0)
            {
                for(int j = 2 * i; j < n; j+= i)
                {
                    prime[j] = 1;
                }
            }
        }

        int ans = 1;
        for(int i = 2; i < n; ++i)
        {
            if(prime[i] == 0)
            {
                ans++;
            }
        }

        return ans;
    }
#endif
};
