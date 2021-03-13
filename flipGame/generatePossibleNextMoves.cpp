#include <vector>
#include <string>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    std::vector<std::string> generatePossibleNextMoves(std::string s)
    {
        std::vector<std::string> res;
        for(int i = 1; i < s.size(); ++i)
        {
            if(s[i] == '+' && s[i - 1] == '+')
            {
                res.push_back(s.substr(0, i - 1) + "--" + s.substr(i + 1));
            }
        }

        return res;
    }
#endif

#if method2
    std::vector<std::string> generatePossibleNextMoves(std::string s)
    {
        std::vector<std::string> res;
        int n = s.length();

        for(int i = 0; i < n; ++i)
        {
            if(s[i] == '+' && s[i + 1] == '+')
            {
                s[i] = s[i + 1] = '-';
                res.push_back(s);
                s[i] = s[i + 1] = '+';
            }
        }

        return res;
    }
#endif;
};
