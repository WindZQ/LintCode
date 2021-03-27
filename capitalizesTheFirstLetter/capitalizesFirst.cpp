#include <string>


class Solution
{
public:
    std::string capitalizesFirst(std::string &s)
    {
        int n = s.size();
        if(s[0] >= 'a' && s[0] <= 'z')
        {
            s[0] -= 32;
        }

        for(int i = 1; i < n; ++i)
        {
            if(s[i - 1] == ' ' && s[i] != ' ')
            {
                s[i] -= 32;
            }
        }

        return s;
    }
}
