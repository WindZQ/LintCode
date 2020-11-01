#include <string>
#include <set>

class Solution
{
public:
    std::string concatenetedString(std::string &s1, std::string &s2)
    {
        std::set<char> set1, set2;
        std::string res;

        for(int i = 0; i < s1.size(); ++i)
        {
            set1.insert(s1[i]);
        }

        for(int i = 0; i < s2.size(); ++i)
        {
            set2.insert(s2[i]);
        }

        for(int i = 0; i < s1.size(); ++i)
        {
            if(set2.find(s1[i]) == set2.end())
            {
                res.push_back(s1[i]);
            }
        }

        for(int i = 0; i < s2.size(); ++i)
        {
            if(set1.find(s2[i]) == set1.end())
            {
                res.push_back(s2[i]);
            }
        }

        return res;
    }
};
