#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
    int shortestDistance(std::vector<std::string> &words, std::string &word1, std::string &word2)
    {
        std::vector<int> idx1, idx2;
        int res = INT_MAX;
        for(int i = 0; i < words.size(); ++i)
        {
            if(words[i] == word1)
            {
                idx1.push_back(i);
            }
            else if(words[i] == word2)
            {
                idx2.push_back(i);
            }
        }

        for(int i = 0; i < idx1.size(); ++i)
        {
            for(int j = 0; j < idx2.size(); ++j)
            {
                res = std::min(res, std::abs(idx1[i] - idx2[j]));
            }
        }

        return res;
    }
#endif

#if method2
    int shortestDistance(std::vector<std::string> &words, std::string &word1, std::string &word2)
    {
        int p1 = -1, p2 = -1, res = INT_MAX;
        for(int i = 0; i < words.size(); ++i)
        {
            if(words[i] == word1)
            {
                p1 = i;
            }
            else if (words[i] == word2)
            {
                p2 = i;
            }

            if(p1 != -1 && p2 != -1)
            {
                res = std::min(res, std::abs(p1 - p2));
            }
        }

        return res;
    }
#endif

#if method3
    int shortestDistance(std::vector<std::string> &words, std::string &word1, std::string &word2)
    {
        int idx = -1, res = INT_MAX;
        for(int i = 0; i < words.size(); ++i)
        {
            if(words[i] == word1 || words[i] == word2)
            {
                if(idx != -1 && words[idx] != words[i])
                {
                    res = std::min(res, i - idx);
                }
                idx = i;
            }
        }

        return res;
    }
#endif
};
