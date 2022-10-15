#include <string>
#include <map>
#include <unordered_map>

#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
    std::string characterDeletion(std::string &str, std::string &sub)
    {
        int temp[256] = {0};
        for (char c : sub)
        {
            temp[c] = 1;
        }

        std::string res = "";
        for (char c : str)
        {
            if (temp[c] == 0)
            {
                res += c;
            }
        }

        return res;
    }
#endif

#if method2
    std::string characterDeletion(std::string &str, std::string &sub)
    {
        std::map<char, int> m;
        for (int i = 0; i < sub.size(); ++i)
        {
            m[sub[i]]++;
        }

        for (auto &i : m)
        {
            str.erase(std::remove(str.begin(), str.end(), i.first), str.end());
        }

        return str;
    }
#endif

#if method3
    std::string characterDeletion(std::string &str, std::string &sub)
    {
        std::unordered_map<char, int> m;
        for (auto i : sub)
        {
            m[i]++;
        }

        std::string res = "";
        for (auto i : str)
        {
            if (m.find(i) == m.end())
            {
                res += i;
            }
        }

        return res;
    }
#endif
}
