#include <vector>

class Solution
{
public:
    int arrayScore(std::vector<int> &nums, int k, long long u, long long l)
    {
        long long sum = 0;
        int score = 0;
        int n = nums.size();

        for(int i = 0; i < k; ++i)
        {
            sum += nums[i];
        }

        if(sum < u) score++;
        if(sum > l) score--;

        for(int i = k; i < n; ++i)
        {
            sum += nums[i];
            sum -= nums[i - k];

            if(sum < u) score++;
            if(sum > l) score--;
        }

        return score;
    }
};
