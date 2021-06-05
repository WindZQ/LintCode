#include <set>

#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
    int countPrimeSetBits(int L, int R)
    {
        int res = 0;
        for(int i = L; i <= R; ++i)
        {
            if(isPrime(bits(i))) ++res;
        }

        return res;
    }

    bool isPrime(int n)
    {
        if(n <= 1) return false;
        if(n == 2) return true;

        for(int i = 2; i <= sqrt(n); ++i)
        {
            if(n % i == 0) return false;
        }

        return true;
    }

    int bits(int n)
    {
        int s = 0;
        while(n)
        {
            s += n & 1;
            n >>= 1;
        }

        return s;
    }
#endif

#if method2
    int countPrimeSetBits(int L, int R)
    {
        int res = 0;
        std::set<int> prime{2, 3, 5, 7, 11, 13, 17, 19};
        for(int i = L; i <= R; ++i)
        {
            if(prime.count(__builtin_popcountll(i))) ++res;
        }

        return res;
    }
#endif

#if method3
    int countPrimeSetBits(int L, int R)
    {
        constexpr int magic = 665772;
        int res = 0;

        for(int i = L; i <= R; ++i)
        {
            if(magic & (1 << __builtin_popcountll(i))) ++res;
        }

        return res;
    }
#endif
};
