#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> chessPieceRotation(std::vector<std::vector<int>> &A, std::vector<std::vector<int>> &F)
    {
        int dx[4] = {0, -1, 0, 1};
        int dy[4] = {-1, 0, 1, 0};

        for(auto item : F)
        {
            int x = item[0] - 1, y = item[1] - 1;
            for(int i = 0; i < 4; ++i)
            {
                if(x + dx[i] > -1 && x + dx[i] < 4 && y + dy[i] > -1 && y + dy[i] < 4)
                {
                    A[x + dx[i]][y + dy[i]] = 1 - A[x + dx[i]][y+dy[i]];
                }
            }
        }

        return A;
    }
};
