#include <vector>
#include <string>
#include <unordered_map>

#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
    bool isToeplitzMatrix(std::vector<std::vector<int>> &matrix)
    {
        for(int i = 0; i < matrix.size() - 1; ++i)
        {
            for(int j = 0; j < matrix[i].size() - 1; ++j)
            {
                if(matrix[i][j] != matrix[i + 1][j + 1])
                    return false;
            }
        }

        return true;
    }
#endif

#if method2
    bool isToeplitzMatrix(std::vector<std::vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        if(m <= 1 || n <= 1) return true;

        for(int i = 1; i < m; ++i)
        {
            if(memcmp(&matrix[i - 1][0], &matrix[i][1], sizeof(int) * (n - 1)) != 0)
                return false;
        }

        return true;
    }
#endif

#if method3
    bool isToeplitzMatrix(std::vector<std::vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        std::unordered_map<int, int> h;

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(h.find(i - j) != h.end())
                {
                    if(h[i - j] != matrix[i][j])
                    {
                        return false;
                    }
                }
                else
                {
                    h[i - j] = matrix[i][j];
                }
            }
        }

        return true;
    }
#endif
};
