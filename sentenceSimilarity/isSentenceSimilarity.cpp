#include <string>
#include <vector>
#include <set>
#include <map>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    bool isSentenceSimilarity(std::vector<std::string> &words1, std::vector<std::string> &words2, std::vector<std::vector<std::string>> &pairs)
    {
        if(words1.size() != words2.size()) return false;
        std::map<std::string, std::set<std::string>> m;
        for(int i = 0; i < pairs.size(); ++i)
        {
            m[pairs[i][0]].insert(pairs[i][1]);
        }

        for(int i = 0; i < words1.size(); ++i)
        {
            if(words1[i] == words2[i]) continue;
            if(!m[words1[i]].count(words2[i]) && !m[words2[i]].count(words1[i])) return false;
        }

        return true;
    }
#endif

#if method2
    bool isSentenceSimilarity(std::vector<std::string> &words1, std::vector<std::string> &words2, std::vector<std::vector<std::string>> &pairs)
    {
        if(words1.size() != words2.size()) return false;
        std::map<std::string, std::set<std::string>> m;
        for(int i = 0; i < pairs.size(); ++i)
        {
            m[pairs[i][0]].insert(pairs[i][1]);
            m[pairs[i][1]].insert(pairs[i][0]);
        }

        for(int i = 0; i < words1.size(); ++i)
        {
            if(words1[i] == words2[i]) continue;
            if(m[words1[i]].count(words2[i]) < 1) return false;
        }

        return true;
    }
#endif
};
