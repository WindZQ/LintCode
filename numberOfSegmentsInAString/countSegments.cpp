#include <string>
#include <vector>


#define method1 1
#define method2 0
#define method3 0
#define method4 0


class Solution
{
public:
#if method1
    int countSegments(std::string &s)
    {
        int res = 0, n = s.size();
        for(int i = 0; i < n; ++i)
        {
            if(s[i] == ' ') continue;
            ++res;
            while(i < n && s[i] != ' ') ++i;
        }

        return res;
    }
#endif

#if method2
    int countSegments(std::string &s)
    {
        int res = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] != ' ' && (i == 0 || s[i - 1] == ' '))
            {
                ++res;
            }
        }

        return res;
    }
#endif

#if method3
    int countSegments(std::string &s)
    {
        int res = 0;
        std::istringstream is(s);
        std::string t = "";
        while(getline(is, t, ' '))
        {
            if(t.empty()) continue;
            ++res;
        }

        return res;
    }
#endif

#if method4
    int countSegments(std::string &s)
    {
        state = SPACEANT;
        int res = 0;
        for(char ch : s)
        {
            go(ch);
            if(state == ADD) ++res;
        }

        return res;
    }

private:
    int state;
    enum STATE {ADD, WORDCANT, SPACEANT};
    std::vector<std::vector<int>> state_map =
    {
        {WORDCANT, SPACEANT},
        {WORDCANT, SPACEANT},
        {ADD, SPACEANT},
    };

    void go(char ch)
    {
        state = state_map[state][ch == ' ' ? 1 : 0];
    }
#endif
};
