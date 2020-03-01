#include <iostream>
#include <string>
#include <algorithm>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    bool Permutation(std::string &A, std::string &B)
    {
        if(A.size() != B.size())
        {
            return false;
        }

        std::sort(A.begin(), A.end());
        std::sort(B.begin(), B.end());
        return A == B ? true : false;
    }
#endif

#if method2
    bool Permutation(std::string &A, std::string &B)
    {
        int tableA[128] = {0};
        int tableB[128] = {0};
        if(A.size() != B.size())
        {
            return false;
        }

        for(int i = 0; i < A.size(); ++i)
        {
            tableA[A.at(i)]++;
            tableB[B.at(i)]++;
        }

        for(int i = 0; i < A.size(); ++i)
        {
            if(tableA[i] != tableB[i])
            {
                return false;
            }
        }
        return true;
    }
#endif
};
