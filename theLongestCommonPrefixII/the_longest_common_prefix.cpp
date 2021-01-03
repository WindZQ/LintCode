#include <vector>
#include <string>

class Solution
{
public:
    int theLongestCommonPrefix(std::vector<std::string> &dic, std::string &target)
    {
        int ans = 0;
        for(std::string it : dic)
        {
            int same = 0;
            for(int i = 0; i < target.size(); ++i)
            {
                if(i > it.size() - 1 || target[i] != it[i])
                {
                    break;
                }
                same++;
            }
            ans = std::max(ans, same);
        }
        return ans;
    }
};
