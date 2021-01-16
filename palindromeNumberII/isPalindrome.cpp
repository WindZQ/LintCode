#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    bool isPalindrome(int n)
    {
        int len = 0, bin[32];
        do
        {
            bin[len++] = n & 1;
            n >>= 1;
        }while(n > 0);

        for(int i = 0; i < len / 2; ++i)
        {
            if(bin[i] != bin[len - i - 1])
            {
                return false;
            }
        }
        return true;
    }
#endif

#if method2
    bool isPalindrome(int n)
    {
        if(n == 0) return true;
        int bits = std::floor(std::log2(std::abs(n))) + 1;
        int l = 0, r = bits - 1;
        while(l < r)
        {
            int num_l = (n >> l) & 1;
            int num_r = (n >> r) & 1;
            if(num_l != num_r) return false;
            l++;
            r--;
        }
        return true;
    }
#endif
};
