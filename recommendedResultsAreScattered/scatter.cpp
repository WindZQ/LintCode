#include <string>
#include <vector>
#include <queue>

class Solution
{
public:
    std::vector<std::string> scatter(std::vector<std::string> &elements, int n)
    {
        std::queue<std::string> q_p, q_v;
        int first_p = -1;

        for(int i = 0; i < elements.size(); ++i)
        {
            if(elements[i][0] == 'P')
            {
                if(first_p == -1)
                {
                    first_p = i;
                }
                q_p.push(elements[i]);
            }
            else
            {
                q_v.push(elements[i]);
            }
        }

        std::vector<std::string> res;
        while(first_p--)
        {
            res.push_back(q_v.front());
            q_v.pop();
        }

        int step;
        while(!q_p.empty())
        {
            res.push_back(q_p.front());
            q_p.pop();
            step = n;

            while(!q_v.empty() && step > 1)
            {
                res.push_back(q_v.front());
                q_v.pop();
                step--;
            }

            if(step > 1)
            {
                break;
            }
        }

        return res;
    }
};
