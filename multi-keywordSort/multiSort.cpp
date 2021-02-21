#include <algorithm>
#include <vector>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    std::vector<std::vector<int>> multiSort(std::vector<std::vector<int>> &array)
    {
        std::sort(array.begin(), array.end(), cmp);
        return array;
    }

    bool cmp(const std::vector<int> &x, const std::vector<int> &y)
    {
        return x[1] != y[1] ? x[1] > y[1] : x[0] < y[0];
    }
#endif

#if method2
    std::vector<std::vector<int>> multiSort(std::vector<std::vector<int>> &array)
    {
        std::vector<int> tmp;
        for(int j = 0; j < array.size() - 1; ++j)
        {
            for(int i = array.size() - 1; i != j; --i)
            {
                if(array[i][1] > array[i - 1][1])
                {
                    tmp = array[i];
                    array[i] = array[i - 1];
                    array[i - 1] = tmp;
                }
                else if(array[i][1] == array[i - 1][1])
                {
                    if(array[i][0] < array[i - 1][0])
                    {
                        tmp = array[i];
                        array[i] = array[i - 1];
                        array[i - 1] = tmp;
                    }
                }
            }
        }

        return array;
    }
#endif
};
