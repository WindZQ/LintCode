#include <string>
#include <vector>
#include <algorithm>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    int calPoints(std::vector<std::string> &ops)
    {
        int ar[1010], pointer = -1, sum = 0;
        for(std::string st : ops)
        {
            char c = st[0];
            if(c == '+')
            {
                sum += (ar[++pointer] = ar[pointer - 1] + ar[pointer - 2]);
            }
            else if(c == 'D')
            {
                sum += (ar[++pointer] = 2 * ar[pointer - 1]);
            }
            else if(c == 'C')
            {
                sum -= ar[pointer--];
            }
            else
            {
                sum += (ar[++pointer] = std::stoi(st));
            }
        }

        return sum;
    }
#endif

#if method2
    int calPoints(std::vector<std::string> &ops)
    {
        std::vector<int> v;
        for(std::string op : ops)
        {
            if(op == "+")
            {
                v.push_back(v.back() + v[v.size() - 2]);
            }
            else if(op == "D")
            {
                v.push_back(2 * v.back());
            }
            else if(op == "C")
            {
                v.pop_back();
            }
            else
            {
                v.push_back(std::stoi(op));
            }
        }

        return std::accumulate(v.begin(), v.end(), 0);
    }
#endif
};
