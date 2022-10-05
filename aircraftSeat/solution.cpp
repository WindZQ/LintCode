#include <string>
#include <vector>

class Solution
{
public:
    int solution(int n, std::string &s)
    {
        std::vector<std::vector<int>> a(n + 1, std::vector<int>(10, 0));
        int t = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ')
            {
                continue;
            }
            else if (s[i] >= '0' && s[i] <= '9')
            {
                t = t * 10 + s[i] - '0';
            }
            else
            {
                a[t][s[i] - 'A'] = 1;
                t = 0;
            }
        }

        int res = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i][1] + a[i][2] + a[i][3] + a[i][4] == 0)
            {
                a[i][1] = a[i][2] = a[i][3] = a[i][4] = 1;
                res++;
            }

            if (a[i][3] + a[i][4] + a[i][5] + a[i][6] == 0)
            {
                a[i][3] = a[i][4] = a[i][5] = a[i][6] = 1;
                res++;
            }

            if (a[i][5] + a[i][6] + a[i][7] + a[i][8] == 0)
            {
                a[i][5] = a[i][6] = a[i][7] = a[i][8] = 1;
                res++;
            }
        }

        return res;
    }
};
