#include <vector>
#include <queue>
#include <pair>

#define method1 1
#define method2 0

class Solution
{
#if method1
public:
    std::vector<std::vector<int>> foolFill(std::vector<std::vector<int>> &image, int sr, int sc, int newColor)
    {
        int m = image.size(), n = image[0].size(), color = image[sr][sc];
        std::vector<std::vector<int>> res = image;
        std::vector<std::vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        std::queue<std::pair<int, int>> q{{{sr, sc}}};

        while(!q.empty())
        {
            int len = q.size();
            for(int i = 0; i < len; ++i)
            {
                auto t = q.front();
                q.pop();
                res[t.first][t.second] = newColor;
                for(auto dir : dirs)
                {
                    int x = t.first + dir[0], y = t.second + dir[1];
                    if(x < 0 || x >= m || y < 0 || y >= n || res[x][y] != color)
                        continue;
                    q.push({x, y});
                }
            }
        }

        return res;
    }
#endif

#if method2
    std::vector<std::vector<int>> foolFill(std::vector<std::vector<int>> &image, int sr, int sc, int newColor)
    {
        if(image[sr][sc] == newColor) return image;
        helper(image, sr, sc, image[sr][sc], newColor);
        return image;
    }

    void helper(std::vector<std::vector<int>> &image, int i, int j, int color, int newColor)
    {
        int m = image.size(), n = image[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || image[i][j] != color) return;
        image[i][j] = newColor;
        helper(image, i + 1, j, color, newColor);
        helper(image, i, j + 1, color, newColor);
        helper(image, i - 1, j, color, newColor);
        helper(image, i, j - 1, color, newColor);
    }
#endif
};
