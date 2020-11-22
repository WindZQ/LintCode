#include <vector>

class Solution
{
public:
    int shortestUnorderedArray(std::vector<int> &arr)
    {
        if(arr.size() == 1) return 0;
        int ans = 1, pos, pre = -1;
        for(int i = 1; i < arr.size(); ++i)
        {
            if(arr[i] != arr[i - 1])
            {
                if(arr[i] < arr[i - 1])
                {
                    ans = -1;
                    pos = i;
                    break;
                }
            }
        }

        for(int i = pos + 1; i < arr.size(); ++i)
        {
            if(ans == -1)
            {
                if(arr[i] > arr[i - 1]) return 3;
            }
            else
            {
                if(arr[i] < arr[i - 1]) return 3;
            }
        }

        return 0;
    }
};
