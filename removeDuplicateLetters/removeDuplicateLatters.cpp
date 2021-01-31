#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    std::stack<int> s1;
    int vis[26], num[26];
    std::string removeDuplicateLetters(std::string &s)
    {
        memset(num, 0, sizeof(num));
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < s.size(); ++i)
        {
            num[s[i] - 'a']++;
        }

        for(int i = 0; i < s.size(); ++i)
        {
            int id = s[i] - 'a';
            num[id]--;
            if(vis[id]) continue;

            while(!s1.empty() && s1.top() > id && num[s1.top()])
            {
                vis[s1.top()] = 0;
                s1.pop();
            }
            s1.push(id);
            vis[id] = 1;
        }

        std::string res = "";
        while(!s1.empty())
        {
            res += char('a' + s1.top());
            s1.pop();
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
#endif

#if method2
    std::string removeDuplicateLetters(std::string &s)
    {
        std::unordered_map<char, int> hash;
        std::unordered_set<char> used;
        std::string res;

        for(char c : s) ++hash[c];
        for(char c : s)
        {
            --hash[c];
            if(used.find(c) != used.end()) continue;
            while(res.size() > 0 && res.back() > c && hash[res.back()])
            {
                used.erase(res.back());
                res.pop_back();
            }
            used.insert(c);
            res.push_back(c);
        }
        return res;
    }
#endif
};
