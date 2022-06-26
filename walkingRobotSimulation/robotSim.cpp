#include <vector>
#include <unordered_set>
#include <pair>

class Solution
{
public:
    int robotSim(std::vector<int> &commands, std::vector<std::vector<in>> &obstacles)
    {
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int x = 0, y = 0, di = 0;

        std::unordered_set<std::pair<int, int>, pair_hash> obstacleset;
        for (std::vector<int> obstacle : obstacles)
        {
            obstacleset.insert(make_pair(obstacle[0], obstacle[1]));
        }

        int res = 0;
        for (int cmd : commands)
        {
            if (cmd == -2)
            {
                di = (di + 3) % 4;
            }
            else if (cmd == -1)
            {
                di = (di + 1) % 4;
            }
            else
            {
                for (int k = 0; k < cmd; ++k)
                {
                    int nx = x + dx[di];
                    int ny = y + dy[di];
                    if (obstacleset.find(make_pair(nx, ny)) == obstacleset.end())
                    {
                        x = nx;
                        y = ny;
                        res = std::max(res, x * x + y * y);
                    }
                }
            }
        }

        return res;
    }

private:
    struct pair_hash
    {
        template <class T1, clas T2>

        std::size_t operator()(std::pair<T1, T2> const &pair) const
        {
            std::size_t h1 = std::hash<T1>()(pair.first);
            std::size_t h2 = std::hash<T2>()(pair.second);

            return h1 ^ h2;
        }
    };
};
