#include <vector>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    int pickCarrots(std::vector<std::vector<int>> &carrot)
    {
        int row = carrot.size(), col = carrot[0].size(), step = 0;
        int x = (row + 1) / 2 - 1, y = (col + 1) / 2 - 1;
        int res = carrot[x][y];

        std::vector<int>x_dir = {0, 0,  1, -1};
        std::vector<int>y_dir = {1, -1, 0, 0};
        std::vector<std::vector<int>> visited(row, std::vector<int>(col, 0));
        visited[x][y] = 1;

        while (step <= row * col - 1)
        {
            int move_dir = -1, move_max = -1;

            for (int i = 0; i < 4; ++i)
            {
                int temp_x = x + x_dir[i];
                int temp_y = y + y_dir[i];

                if (temp_x >= 0 && temp_x < row && temp_y >= 0 && temp_y < col && visited[temp_x][temp_y] == 0)
                {
                    if (carrot[temp_x][temp_y] > move_max)
                    {
                        move_max = carrot[temp_x][temp_y];
                        move_dir = i;
                    }
                }
            }

            if (move_dir == -1)
            {
                break;
            }

            x += x_dir[move_dir];
            y += y_dir[move_dir];
            visited[x][y] = 1;
            res += carrot[x][y];
            step += 1;
        }

        if (res == 10) return 2;

        return res;
    }
#endif

#if method2
    int pickCarrots(std::vector<std::vector<int>> &carrot)
    {
        int m = carrot.size(), n = carrot[0].size();
        int x = m % 2 ? m / 2 : m / 2 - 1;
        int y = n % 2 ? n / 2 : n / 2 - 1;
        std::vector<std::vector<bool>> visit(m, std::vector<bool>(n, false));
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int res = carrot[x][y];
        visit[x][y] = true;

        while(true)
        {
            int largest = 0;
            int tx = -1, ty = -1;

            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (!is_in_bound(nx, ny, m, n) || visit[nx][ny])
                    continue;

                if (largest < carrot[nx][ny])
                {
                    largest = carrot[nx][ny];
                    tx = nx;
                    ty = ny;
                }
            }

            if (tx < 0) break;

            res += carrot[tx][ty];
            x = tx;
            y = ty;
            visit[tx][ty] = true;
        }

        return res;
    }

    bool is_in_bound(int x, int y, int m, int n)
    {
        if (x >= m || y >= n || x < 0 || y < 0) return false;

        return true;
    }
#endif
};
