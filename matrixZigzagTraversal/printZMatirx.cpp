#include <iostream>
#include <vector>

#define method1 1
#define method2 0
#define method3 0


class Solution
{
public:
#if method1
    std::vector<int> printZMatrix(std::vector<std::vector<int>> &matrix)
    {
        std::vector<int> z;
        if(matrix.size() == 0)
        {
            return z;
        }
        else
        {
            if(matrix[0].size() == 0)
            {
                return z;
            }
        }

        int x = 0, y = 0, dx = -1, dy = 1, count = 1, m = matrix.size(), n = matrix[0].size();
        z.push_back(matrix[0][0]);

        while(count < m * n)
        {
            if(x + dx >= 0 && y + dy >= 0 && x + dx < m && y + dy < n)
            {
                x += dx;
                y += dy;
            }
            else
            {
                if(dx == -1 && dy == 1)
                {
                    if(y + 1 < n)
                    {
                        ++y;
                    }
                    else
                    {
                        ++x;
                    }
                    dx = 1;
                    dy = -1;
                }
                else
                {
                    if(x + 1 < m)
                    {
                        ++x;
                    }
                    else
                    {
                        ++y;
                    }
                    dx = -1;
                    dy = 1;
                }
            }
            z.push_back(matrix[x][y]);
            count++;
        }
        return z;
    }
#endif

#if method2
    std::vector<int> printZMatrix(std::vector<std::vector<int>> &matrix)
    {
        std::vector<int> v;
        int m = matrix.size(), n = matrix[0].size();
        if(m == 0 || n == 0)
        {
            return v;
        }
        for(int i = 0; i <= m + n; ++i)
        {
            if(i % 2 == 0)
            {
                for(int j = i; j >= 0; --j)
                {
                    if((i - j) < n && j < m)
                    {
                        v.push_back(matrix[j][i - j]);
                    }
                }
            }
            else
            {
                for(int j = 0; j <= i; ++j)
                {
                    if((i - j) < n && j < m)
                    {
                        v.push_back(matrix[j][i - j]);
                    }
                }
            }
        }
        return v;
    }
#endif

#if method3
    std::vector<int> printZMatrix(std::vector<std::vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        std::vector<int> v(m * n);
        int row = 0, col = 0;
        bool up = true;
        if(m == 0 || n == 0)
        {
            return v;
        }

        for(int i = 0; i < v.size(); ++i)
        {
            v[i] = matrix[row][col];
            if(up)
            {
                if(row - 1 >= 0 && col + 1 < n)
                {
                    --row;
                    ++col;
                }
                else if(col + 1 < n)
                {
                    ++col;
                    up = false;
                }
                else
                {
                    ++row;
                    up = false;
                }
            }
            else
            {
                if(row + 1 < m && col - 1 >= 0)
                {
                    ++row;
                    --col;
                }
                else if(row + 1 < m)
                {
                    ++row;
                    up = true;
                }
                else
                {
                    ++col;
                    up = true;
                }
            }
        }
        return v;
    }
#endif
};
