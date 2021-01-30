#include <string>
#include <unordered_map>
#include <iostream>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    bool wordPattern(std::string &pattern, std::string &teststr)
    {
        std::unordered_map<char, std::string> m;
        std::istringstream in(teststr);
        int i = 0, n = pattern.size();

        for(std::string word; in >> word; ++i)
        {
            if(i >= n) continue;
            if(m.count(pattern[i]))
            {
                if(m[pattern[i]] != word) 
				{
					return false;
				}
            }
			else
            {
                for(auto a : m)
                {
                    if(a.second == word) return false;
                }
                m[pattern[i]] = word;
            }
        }
        return i == n;
    }
#endif

#if method2
    bool wordPattern(std::string &pattern, std::string &teststr)
    {
        std::unordered_map<char, int> m1;
        std::unordered_map<std::string, int> m2;
        std::istringstream in(teststr);
        int i = 0, n = pattern.size();

        for(std::string word; in >> word; ++i)
        {
            if(i == n || m1[pattern[i]] != m2[word])  return false;
            m1[pattern[i]] = m2[word] = i + 1;
        }

        return i == n;
	}
#endif
};
