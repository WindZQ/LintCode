#include <vector>

class Solution
{
public:
    int subarrays(std::vector<int> &array)
    {
        int n = array.size();
        if(n <= 1) return 0;
        int result = 0;

        std::vector<int> freqs;
        int count = 1;

        for(int i = 1; i < n; ++i)
        {
            if(array[i] == array[i - 1])
            {
                count++;
            }
            else
            {
                freqs.push_back(count);
                count = 1;
            }
        }
        freqs.push_back(count);

        n = freqs.size() - 1;
        for(int i = 0; i < n; ++i)
        {
            result += std::min(freqs[i], freqs[i + 1]);
        }
        return result;
    }
};
