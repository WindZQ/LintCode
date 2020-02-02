#include <iostream>
#include <vector>

#define method1 1

class Solution
{
public:
#if method1
    int removeElement(std::vector<int> &A, int elem)
    {
        int start = 0;
        int len = A.size();

        for(int i = 0; i < len; ++i)
        {
            if(elem != A[i])
            {
                A[start++] = A[i];
            }
        }
        return start;
    }
#endif
};

int main(void)
{
    std::vector<int> A{0, 4, 4, 0, 0, 2, 4, 4};
    int elem = 4;
    Solution s;

    std::cout << s.removeElement(A, elem) << std::endl;

    return 0;
}
