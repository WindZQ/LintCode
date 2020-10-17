#include <string>
#include <vector>
#include <set>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    int countRotateWords(std::vector<std::string> words)
    {
        std::set<std::string> dict;
        for(std::string w : words)
        {
            std::string s = w + w;
            for(int i = 0; i < w.size(); ++i)
            {
                dict.erase(s.substr(i, w.size()));
            }
            dict.insert(w);
        }

        return dict.size();
    }
#endif

#if method2
    int countRotateWords(std::vector<std::string> words)
    {
        int size = words.size();
        if(words.size() == 0) return 0;

        for(int i = 0; i < size; ++i)
        {
            words[i] = change_word_to_smallest(words[i]);
        }
        std::sort(words.begin(), words.end());

        std::vector<std::string> v;
        v.push_back(words[0]);

        for(int i = 1; i < size; ++i)
        {
            if(std::find(v.begin(), v.end(), words[i]) != v.end())
            {

            }
            else
            {
                v.push_back(words[i]);
            }
        }

        return v.size();
    }

    std::string change_word_to_smallest(const std::string &str)
     {
         int size = str.size();
         std::vector<std::string> v;
         int offset = size;
         while(offset--)
         {
             v.push_back(str.substr(size - offset, offset) + str.substr(0, size - offset));
         }

         sort(v.begin(), v.end());
         return *v.begin();
     }
#endif
};
