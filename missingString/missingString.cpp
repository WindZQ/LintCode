#include <string>
#include <vector>
#include <unordered_set>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    std::vector<std::string> missingString(std::string &str1, std::string &str2)
    {
        int len1 = str1.size(), len2 = str2.size();
        std::unordered_set<std::string> word_list;
        std::vector<std::string> res;
        std::string tmp = "";

        for(int i = 0; i < len2; ++i)
        {
            while(str2[i] != ' ' && i < len2)
            {
                tmp += str2[i];
                ++i;
            }

            word_list.insert(tmp);
            tmp = "";
        }

        for(int i = 0; i < len1; ++i)
        {
            while(str1[i] != ' ' && i < len1)
            {
                tmp += str1[i];
                ++i;
            }

            if(word_list.find(tmp) == word_list.end())
            {
                res.push_back(tmp);
            }
            tmp = "";
        }

        return res;
    }
#endif

#if method2
    std::vector<std::string> missingString(std::string &st1, std::string &str2)
    {
        std::vector<std::string> v1;
        std::vector<std::string> v2;
        std::vector<std::string> res;

        std::string buf;
        std::stringstream ss1(str1);
        while(ss1 >> buf)
        {
            v1.push_back(buf);
        }

        std::stringstream ss2(str2);
        while(ss2 >> buf)
        {
            v2.push_back(buf);
        }

        for(int i = 0; i < v1.size(); ++i)
        {
            std::vector<std::string>::iterator it;
            it = std::find(v2.begin(), v2.end(), v1[i]);
            if(it == v2.end())
            {
                res.push_back(v1[i]);
            }
        }

        return res;
    }
#endif
};
