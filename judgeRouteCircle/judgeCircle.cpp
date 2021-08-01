#include <string>
#include <unordered_map>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    bool judgeCircle(std::string &moves)
    {
        int cnt1 = 0, cnt2 = 0;

        for(char move : moves)
        {
            if(move == 'U') ++cnt1;
            else if(move == 'D') --cnt1;
            else if(move == 'L') ++cnt2;
            else if(move == 'R') --cnt2;
        }

        return cnt1 == 0 && cnt2 == 0;
    }
#endif

#if method2
    bool judgeCircle(std::string &moves)
    {
        std::unordered_map<char, int> m;
        for(char c : moves) ++m[c];
        return m['L'] == m['R'] && m['U'] == m['D'];
    }
#endif
};
