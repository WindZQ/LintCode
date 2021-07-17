#include <string>

#define method1 1
#define method2 0
#define method3 0


class Solution
{
public:
#if method1
    int repeatedStringMatch(std::string &A, std::string &B)
    {
        int n1 = A.size(), n2 = B.size(), cnt = 1;
        std::string t = A;
        while(t.size() < n2)
        {
            t += A;
            ++cnt;
        }

        if(t.find(B) != std::string::npos) return cnt;
        t += A;

        return (t.find(B) != string::npos) ? cnt + 1 : -1;
    }
#endif

#if method2
    int repeatedStringMatch(std::string &A, std::string &B)
    {
        std::string t = A;

        for(int i = 1; i <= B.size() / A.size() + 2; ++i)
        {
            if(t.find(B) != string::npos) return i;
            t += A;
        }

        return -1;
    }
#endif

#if method3
    int repeatedStringMatch(std::string &A, std::string &B)
    {
        int m = A.size(), n = B.size();

        for(int i = 0; i < m; ++i)
        {
            int j = 0;
            while(j < n && A[(i + j) % m] == B[j]) ++j;
            if(j == n) return (i + j - 1) / m + 1;
        }

        return -1;
    }
#endif
};
