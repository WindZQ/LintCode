#include <string>
#include <vector>
#include <unordered_set>
#include <set>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    int uniqueMorseRepresentations(std::vector<std::string> &words)
    {
        std::vector<std::string> morse{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        std::unordered_set<std::string> s;
        for (std::string word : words)
        {
            std::string t = "";
            for (char c : word) t += morse[c - 'a'];
            s.insert(t);
        }

        return s.size();
    }
#endif

#if method2
    int uniqueMorseRepresentations(std::vector<std::string> &words)
    {
        std::string d[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        std::set<std::string> s;
        for (int i = 0; i < words.size(); ++i)
        {
            std::string code = "";
            for (int j = 0; j < words[i].size(); ++j)
            {
                code += d[words[i][j] - 'a'];
            }
            s.insert(code);
        }

        return s.size();
    }
#endif
};
