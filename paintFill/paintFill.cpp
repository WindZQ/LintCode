#include <iostream>
#include <vector>

class Solution
{
public:
    bool paintFill(std::vector<std::vector<int>> &screen, int x, int y, int newColor)
    {
        return screen[x][y] != newColor;
    }
};
