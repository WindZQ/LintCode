#include <string>
#include <vector>
#include <unordered_map>


class Solution
{
public:
    std::vector<std::string> findRestaurant(std::vector<std::string> &list1, std::vector<std::string> &list2)
    {
        std::vector<std::string> res;
        std::unordered_map<std::string, int> m;
        int mn = INT_MAX, n1 = list1.size(), n2 = list2.size();
        for(int i = 0; i < n1; ++i)
        {
            m[list1[i]] = i;
        }

        for(int i = 0; i < n2; ++i)
        {
            if(m.count(list2[i]))
            {
                int sum = i + m[list2[i]];
                if(sum == mn)
                {
                    res.push_back(list2[i]);
                }
                else if(sum < mn)
                {
                    mn = sum;
                    res = {list2[i]};
                }
            }
        }

        return res;
    }
};
