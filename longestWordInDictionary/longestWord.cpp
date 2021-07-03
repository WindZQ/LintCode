#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

#define method1 1
#define method2 0
#define method3 0

class Solution
{
#if method1
    std::string longestWord(std::vector<std::string> &words)
    {
        std::string res = "";
        int len = 0;
        std::unordered_set<std::string> s(words.begin(), words.end());
        std::queue<std::string> q;
		for(std::string word : words)
		{
			if(word.size() == 1) q.push(word);
		}

        while(!q.empty())
        {
            std::string t = q.front();
            q.pop();
            if(t.size() > len)
            {
                len = t.size();
                res = t;
            }
            else if(t.size() == len)
            {
                res = std::min(res, t);
            }

            for(char c = 'a'; c <= 'z'; ++c)
            {
                t.push_back(c);
                if(s.count(t)) q.push(t);
                t.pop_back();
            }
        }

        return res;
    }
#endif

#if method2
    std::string longestWord(std::vector<std::string> &words)
    {
        std::string res = "";
        int len = 0;
        std::unordered_set<std::string> s(words.begin(), words.end());
        for(std::string word : words)
        {
            if(word.size() == 1)
                helper(s, word, len, res);
        }

        return res;
    }

    void helper(std::unordered_set<std::string> &s, std::string word, int &len, std::string &res)
    {
        if(word.size() > len)
        {
            len = word.size();
            res = word;
        }
        else if(word.size() == len)
        {
            res = std::min(res, word);
        }

        for(char c = 'a'; c <= 'z'; ++c)
        {
            word.push_back(c);
            if(s.count(word))
                helper(s, word, len, res);
            word.pop_back();
        }
    }
#endif

#if method3
    std::string longestWord(std::vector<std::string> &words)
    {
        std::string res = "";
        std::unordered_set<std::string> s;
        std::sort(words.begin(), words.end());

        for(std::string word : words)
        {
            if(word.size() == 1 || s.count(word.substr(0, word.size() - 1)))
            {
                res = (word.size() > res.size()) ? word : res;
                s.insert(word);
            }
        }

        return res;
    }
#endif
};
