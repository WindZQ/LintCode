#include <string>
#include <stack>
#include <algorithm>

#define methdod1 1
#define methdod2 0

class Solution
{
public:
#if methdod1
    std::string SumofTwoStrings(std::string &A, std::string &B)
    {
        std::string res = "";
        int i = A.size() - 1, j = B.size() - 1;

        for(; i >= 0 && j >= 0; i--, j--)
        {
            res = std::to_string(A[i] - '0' + B[j] - '0') + res;
        }

        if(i >= 0) res = A.substr(0, i + 1) + res;
        if(j >= 0) res = B.substr(0, j + 1) + res;

        return res;
    }
#endif

#if methdod2
    std::string SumofTwoStrings(std::string &A, std::string &B)
     {
         std::string res;
         std::stack<std::string> s;

         int sz = std::max(A.size(), B.size()) - 1;
         for(int i = A.size() - 1, j = B.size() - 1; sz >= 0; i--, j--, sz--)
         {
             int a = i < 0 ? 0 : (A[i] - '0');
             int b = j < 0 ? 0 : (B[j] - '0');
             s.push(std::to_string(a + b));
         }

         while(!s.empty())
         {
             res += s.top();
             s.pop();
         }

         return res;
     }
#endif
};
