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
    std::vector<std::string> letterCasePermutation(std::string &S)
    {
        std::vector<std::string> res{""};

        for(char c : S)
        {
            int len = res.size();
            if(c >= '0' && c <= '9')
            {
                for(std::string &str : res)
                    str.push_back(c);
            }
            else
            {
                for(int i = 0; i < len; ++i)
                {
                    res.push_back(res[i]);
                    res[i].push_back(tolower(c));
                    res[len + i].push_back(toupper(c));
                }
            }
        }

        return res;
    }
#endif

#if method2
    std::vector<std::string> letterCasePermutation(std::string &S)
    {
        std::vector<std::string> res{""};

        for(char c : S)
        {
            int len = res.size();
            if(c >= '0' && c <= '9')
            {
                for(std::string &str : res)
                    str.push_back(c);
            }
            else
            {
                for(int i = 0; i < len; ++i)
                {
                    res.push_back(res[i]);
                    res[i].push_back(c);
                    res[len + i].push_back(c ^ 32);
                }
            }
        }

        return res;
    }
#endif

#if method3
    std::vector<std::string> letterCasePermutation(std::string &S)
    {
        std::vector<std::string> res;
        helper(S, 0, res);
        return res;
    }

    void helper(std::string &s, int pos, std::vector<std::string> &res)
    {
        if(pos == s.size())
        {
            res.push_back(s);
            return;
        }

        helper(s, pos + 1, res);

        if(s[pos] > '9')
        {
            s[pos] ^= 32;
            helper(s, pos + 1, res);
        }
    }
#endif

#if method4
    std::vector<std::string> letterCasePermutation(std::string &S)
    {
        std::vector<std::string > res;
        int cnt = 0;
        for(char c : S)
        {
            if(c > '9') ++cnt;
        }

        for(int i = 0; i < (1 << cnt); ++i)
        {
            int j = 0;
            std::string word = "";
            for(char c : S)
            {
                if(c > '9')
                {
                    if(((i >> j++) & 1) == 1)
                    {
                        word.push_back(tolower(c));
                    }
                    else
                    {
                        word.push_back(toupper(c));
                    }
                }
                else
                {
                    word.push_back(c);
                }
            }

            res.push_back(word);
        }

        return res;
    }
#endif
};
