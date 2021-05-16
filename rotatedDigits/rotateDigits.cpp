#include <string>
#include <vector>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    int rotatedDigits(int N)
    {
        int res = 0;
        for(int i = 0; i <= N; ++i)
        {
            if(check(i)) ++ res;
        }

        return res;
    }

    bool check(int k)
    {
        std::string str = to_string(k);
        bool flag = false;

        for(char c : str)
        {
            if(c == '3' || c == '4' || c == '7') return false;
            if(c == '2' || c == '5' || c == '6' || c == '9') flag = true;
        }

        return flag;
    }
#endif

#if method2
    int rotatedDigits(int N)
    {
        int res = 0;
        std::vector<int> dp(N + 1);

        for(int i = 0; i <= N; ++i)
        {
            if(i < 10)
            {
                if(i == 0 || i == 1 || i == 8)
                {
                    dp[i] = 1;
                }
                else if(i == 2 || i == 5 || i == 6 || i == 9)
                {
                    dp[i] = 2;
                    ++res;
                }
            }
            else
            {
                int a = dp[i / 10], b = dp[i % 10];
                if(a == 1 && b == 1)
                {
                    dp[i] = 1;
                }
                else if(a >= 1 && b >= 1)
                {
                    dp[i] = 2;
                    ++res;
                }
            }
        }
        return res;
    }
#endif
};
