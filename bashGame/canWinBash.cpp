#define method1 1
#define method2 0


class Solution
{
public:
#if method1
    bool canWinBash(int n)
    {
        return n % 4;
    }
#endif

#if method2
    bool canWinBash(int n)
    {
        return n & 3;
    }
#endif
};
