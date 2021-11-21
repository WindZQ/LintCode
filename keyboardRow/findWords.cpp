#include <vector>
#include <string>
#include <unordered_set>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    std::vector<std::string> findWords(std::vector<std::string> &words)
    {
        std::vector<std::string> res;
        std::unordered_set<char> row1{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
        std::unordered_set<char> row2{'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        std::unordered_set<char> row3{'z', 'x', 'c', 'v', 'b', 'n', 'm'};

        for(std::string word : words)
        {
            int one = 0, two = 0, three = 0;
            for(char c : word)
            {
                if(c < 'a') c += 32;
                if(row1.count(c)) one = 1;
                if(row2.count(c)) two = 1;
                if(row3.count(c)) three = 1;
                if(one + two + three > 1) break;
            }
            if(one + two + three == 1) res.push_back(word);
        }

        return res;
    }
#endif

#if method2
    std::vector<std::string> findWords(std::vector<std::string> &words)
    {
        std::vector<std::string> res;
        std::string row_idx = "12210111011122000010020202";

        for(auto &word : words)
        {
            bool is_valid = true;
            char idx = row_idx[tolower(word[0]) - 'a'];
            for(int i = 1; i < word.size(); ++i)
            {
                if(row_idx[tolower(word[i]) - 'a'] != idx)
                {
                    is_valid = false;
                    break;
                }
            }

            if(is_valid) res.push_back(word);
        }

        return res;
    }
#endif
};
