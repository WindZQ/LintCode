#include <string>
#include <vector>
#include <map>
#include <unordered_set>

#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
    std::vector<std::string> nameDeduplication(std::vector<std::string> &names)
    {
        std::map<std::string, bool> m;
        std::vector<std::string> result;
        for(auto &str : names)
        {
            std::transform(str.begin(), str.end(), str.begin(), ::tolower);
            if(m.find(str) == m.end())
            {
                m[str] = true;
                result.push_back(str);
            }
        }

        return result;
    }
#endif

#if method2
    std::vector<std::string> nameDeduplication(std::vector<std::string> &names)
    {
        std::map<std::string, int> m;
        std::vector<std::string> result;
        int size = names.size();

        for(int i = 0; i < size; ++i)
        {
            for(int j = 0; j < (int)names[i].size(); ++j)
            {
                names[i][j] = std::tolower(names[i][j]);
            }
            m.insert(std::pair<std::string, int>(names[i], 1));
        }

        std::map<std::string, int>::iterator it = m.begin();
        for(; it != m.end(); ++it)
        {
            result.push_back(it->first);
        }
        return result;
    }
#endif

#if method3
    std::vector<std::string> nameDeduplication(std::vector<std::string> &names)
    {
        std::unordered_set<std::string> str;
        std::vector<std::string> result;
        for(int i = 0; i < names.size(); ++i)
        {
            for(int j = 0; j < names[i].size(); ++j)
            {
                names[i][j] = std::tolower(names[i][j]);
            }
            str.insert(names[i]);
        }

        for(auto it = str.begin(); it != str.end(); ++it)
        {
            result.push_back(*it);
        }
        return result;
    }
#endif
};
