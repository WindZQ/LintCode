#include <string>
#include <vector>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    bool validWordSquare(std::vector<std::string> &words)
    {
        if(words.size() != words[0].size()) return false;

        for(int i = 0; i < words.size(); ++i)
        {
            for(int j = 0; j < words[i].size(); ++j)
            {
                if(j >= words.size() || i >= words[j].size() || words[i][j] != words[j][i])
                {
                    return false;
                }
            }
        }

        return true;
    }
#endif

#if method2
    bool validWordSquare(std::vector<std::string> &words)
    {
        int i = 0;
        for(const std::string &word : words)
        {
            for(int j = 0; j < word.length(); ++j)
            {
                if(j >= words.size()) return false;
                if(words[j][i] != word[j]) return false;
            }
            ++i;
        }

        return true;
    }
#endif
};
