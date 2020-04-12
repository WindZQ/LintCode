#include <iostream>
#include <vector>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    int longestIncreasingContinuousSubsequence(std::vector<int> &A)
    {
        int max = 1, s = 1, l = 1, len = A.size();
        if(len == 0) return 0;
        for(int i = 1; i < len; ++i)
        {
            if(A[i] > A[i - 1])
            {
                s += i;
            }
            else
            {
                if(s > max)
                {
                    max = s;
                }
            }

            if(A[i] < A[i - 1])
            {
                l += 1;
            }
            else
            {
                if(l > max)
                {
                    max = l;
                    l = 1;
                }
            }
        }

        if(s > max) max = s;
        if(l > max) max = l;
        return max;
    }
#endif

#if method2
    int result = 0;

    void calc(std::vector<int> &A, int len)
    {
        std::vector<int> f(len, 1);
        for(int i = 0; i < len; ++i)
        {
            if(i > 0 && A[i] > A[i - 1])
            {
                f[i] = f[i - 1] + 1;
            }
            if(f[i] > result) result = f[i];
        }
    }

    int longestIncreasingContinuousSubsequence(std::vector<int> &A)
    {
        int len = A.size();
        if(len == 0) return 0;
        calc(A, len);
        int i = 0, j = len - 1;
        while(i < j)
        {
            std::swap(A[i], A[j]);
            i++;
            j--;
        }
        calc(A, len);
        return result;
    }
#endif
};
