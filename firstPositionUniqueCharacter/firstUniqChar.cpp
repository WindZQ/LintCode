#include <string>
#include <unordered_map>
#include <vector>
#icnlude <pair>

#define method1 1
#define method2 0
#define method3 0


class Solution
{
public:
#if method1
    int firstUniqChar(std::string &s)
    {
        int res = INT_MAX;
        std::unordered_map<char, std::pair<size_t, int>> hash_table;
        for(size_t i = 0; i < s.length(); ++i)
        {
            if(hash_table.find(s[i]) == hash_table.end())
            {
                hash_table[s[i]] = std::make_pair(1, i);
            }
            else
            {
                ++hash_table[s[i]].first;
            }
        }

        for(auto elem : hash_table)
        {
            if(elem.second.first == 1)
            {
                res = std::min(res, elem.second.second);
            }
        }

        if(res == INT_MAX)
        {
            return -1;
        }
        else
        {
            return res;
        }
    }
#endif

#if method2
    int firstUniqChar(std::string &s)
    {
        std::vector<int> cnt(256, 0);
        for(int i = 0; i < s.size(); ++i)
        {
            cnt[s[i]]++;
        }

        for(int i = 0; i < s.size(); ++i)
        {
            if(cnt[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
#endif

#if method3
    int firstUniqChar(std::string &s)
    {
        std::unordered_map<char, int> hash_table;

        for(int i = 0; i < s.size(); ++i)
        {
            hash_table[s[i]]++;
        }

        for(int i = 0; i < s.size(); ++i)
        {
            if(hash_table[s[i]] == 1)
            {
                return i;
            }
        }

        return -1;
    }
#endif
};
