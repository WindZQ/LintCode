#include <vector>
#include <algorithm>

#define method1 1
#define method2 0


class Solution
{
public:
#if method1
    std::vector<int> constructRectangle(int area)
    {
        int r = std::sqrt(area);
        while(area % r != 0) --r;
        return { area / r, r};
    }
#endif

#if method2
    std::vector<int> constructRectangle(int area)
    {
        int r = 1;
        for(int i = 1; i * i <= area; ++i)
        {
            if(area % i == 0) r = i;
        }

        return { area / r, r};
    }
#endif
};
