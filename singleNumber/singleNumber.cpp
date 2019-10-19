#include <iostream>
#include <vector>
#include <unordered_set>
#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
    //时间复杂度为O(n),空间复杂度为O(n)
#if method1
    int singleNumber(std::vector<int> &A)
    {
        std::unordered_set<int> res;
        for(int i = 0;i < A.size(); ++i)
        {
            if(res.count(A[i]))
                res.erase(A[i]);
            else
                res.insert(A[i]);
        }
        return *res.begin();
    }
#endif

    //时间复杂度为O(n^2),空间复杂度为O(1)
#if method2
    int singleNumber(std::vector<int> &A)
    {
        bool flag = false;
        int len = A.size();
        for(int i = 0; i < len; ++i)
        {
            for(int j = 0; j < len; ++j)
            {
                if(A[i] == A[j] && i != j)
                {
                    flag = true;
                    break;
                }
            }
            if(false == flag)
                return A[i];
            else
                flag = false;
        }
        return 0;
    }
#endif

    //时间复杂度为O(1),空间复杂度为O(1)
#if method3
    int singleNumber(std::vector<int> &A)
    {
        int x;
        for(int i = 0; i < A.size(); ++i)
            x ^= A[i];
        return x;
    }
#endif
};

int main()
{
    Solution s;
    std::vector<int> A{1, 1, 2, 2, 3, 4, 4};
    std::cout << s.singleNumber(A) << std::endl;
    return 0;
}
