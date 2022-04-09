#include <vector>
#include <algorithm>

#define method1 1
#define method2 0


class Solution
{
public:
#if method1
    int ParkingDilemma(std::vector<int> &cars, int k)
    {
        std::sort(cars.begin(), cars.end());

        int ret = INT_MAX;
        for(int i = 0; i < cars.size(); ++i)
        {
            if(i < k - 1) continue;
            ret = std::min(ret, cars[i] - cars[i - k + 1] + 1);
        }

        return ret;
    }
#endif

#if method2
    int ParkingDilemma(std::vector<int> &cars, int k)
    {
        std::sort(cars.begin(), cars.end());
        int j = k - 1, i = 0;
        int root_length = INT_MAX;

        for(int i = 0; j < cars.size(); ++i, ++j)
        {
            root_length = std::min(root_length, cars[j] - cars[i] + 1);
        }

        return root_length;
    }
#endif
};
