#include <vector>

#define method1 1
#define method2 0
#define method3 0


class Solution
{
public:
#if method1
    bool canPlaceFlowers(std::vector<int> &flowerbed, int n)
    {
        if(flowerbed.empty()) return false;
        if(flowerbed[0] == 0) flowerbed.insert(flowerbed.begin(), 0);
        if(flowerbed.back() == 0) flowerbed.push_back(0);
        int len = flowerbed.size(), cnt = 0, sum = 0;

        for(int i = 0; i <= len; ++i)
        {
            if(i < len && flowerbed[i] == 0)
            {
                ++cnt;
            }
            else
            {
                sum += (cnt - 1) / 2;
                cnt = 0;
            }
        }

        return sum >= n;
    }
#endif

#if method2
    bool canPlaceFlowers(std::vector<int> &flowerbed, int n)
    {
        for(int i = 0;i < flowerbed.size(); ++i)
        {
            if(n == 0) return true;
            if(flowerbed[i] == 0)
            {
                int next = (i == flowerbed.size() - 1  ? 0 : flowerbed[i + 1]);
                int pre = (i == 0 ? 0 : flowerbed[i - 1]);
                if(next + pre == 0)
                {
                    flowerbed[i] = 1;
                    --n;
                }
            }
        }

        return n <= 0;
    }
#endif

#if method3
    bool canPlaceFlowers(std::vector<int> &flowerbed, int n)
    {
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);

        for(int i = 1; i < flowerbed.size() - 1; ++i)
        {
            if(n == 0) return true;
            if(flowerbed[i - 1] + flowerbed[i]  + flowerbed[i + 1] == 0)
            {
                --n;
                ++i;
            }
        }

        return n <= 0;
    }
#endif
};
