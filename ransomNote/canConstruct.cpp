#include <string>
#include <vector>
#include <unordered_map>

#define method1 1
#define method2 0


class Solution
{
public:
#if method1
    bool canConstruct(std::string &ransomNote, std::string &magazine)
    {
        std::unordered_map<char, int> m;
        for(char c : magazine) ++m[c];
        for(char c : ransomNote)
        {
            if(--m[c] < 0) return false;
        }

        return true;
    }
#endif

#if method2
    bool canConstruct(std::string &ransomNote, std::string &magazine)
    {
        if(ransomNote.size() > magazine.size()) return false;
        std::vector<int> cnt(26);
        for(auto &c : magazine)
        {
            cnt[c - 'a']++;
        }

        for(auto &c : ransomNote)
        {
            cnt[c - 'a']--;
            if(cnt[c - 'a'] < 0) return false;
        }

        return true;
    }
#endif
};
