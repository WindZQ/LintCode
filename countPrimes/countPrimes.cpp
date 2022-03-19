#include <vector>

#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
    bool is_prime(int x)
    {
        for(int i = 2; i * i <= x; ++i)
        {
            if(x % i == 0) return false;
        }

        return true;
    }

    int countPrimes(int n)
    {
        int res = 0;

        for(int i = 2; i < n; ++i)
        {
            res += is_prime(i);
        }

        return res;
    }
#endif

#if method2
    int countPrimes(int n)
    {
        std::vector<int> is_prime(n, 1);
        int res = 0;

        for(int i = 2; i < n; ++i)
        {
            if(is_prime[i])
            {
                res += 1;
                if((long long)i * i < n)
                {
                    for(int j = i * i; j < n; j += i)
                    {
                        is_prime[j] = 0;
                    }
                }
            }
        }

        return res;
    }
#endif

#if method3
    int countPrimes(int n)
    {
        std::vector<int> primes;
        std::vector<int> is_prime(n, 1);

        for(int i = 2; i < n; ++i)
        {
            if(is_prime[i])
            {
                primes.push_back(i);
            }

            for(int j = 0; j < primes.size() && i * primes[j] < n; ++j)
            {
                is_prime[i * primes[j]] = 0;
                if(i % primes[j] == 0)
                {
                    break;
                }
            }
        }

        return primes.size();
    }
#endif
};
