#include <vector>

class Solution
{
public:
    int maxNonNegativeSubArray(std::vector<int> &A)
    {
        int n = A.size();
        if(n == 0) return 0;
        int sum = 0, max_sum = 0;
        int count = 0;

        for(int i = 0; i < n; ++i)
        {
            if(A[i] < 0)
            {
                sum = 0;
            }
            else
            {
                sum += A[i];
                count++;
            }

            if(max_sum < sum)
            {
                max_sum = sum;
            }
        }
        if(count == 0) return -1;
        return max_sum;
    }
};
