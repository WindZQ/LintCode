#include <string>
#include <unordered_set>

#define method1 1
#define method2 0


class Solution
{
public:
#if method1
    int numJewelsInStones(std::string &J, std::string &S)
    {
        int res = 0;
        for(char s : S)
        {
            for(char j : J)
            {
                if(s == j)
                {
                    ++res;
                    break;
                }
            }
        }
        return res;
    }
#endif

#if method2
    int numJewelsInStones(std::string &J, std::string &S)
    {
        int res = 0;
        std::unordered_set<char> s;
        for(char c : J) s.insert(c);
        for(char c : S)
        {
            if(s.count(c)) ++res;
        }

        return res;
    }
#endif
};
