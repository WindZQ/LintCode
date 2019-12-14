#include <iostream>
#include <string>
#include <vector>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    std::vector<std::string> longestWords(std::vector<std::string> &dictionary)
    {
        int maxLength = 0;
        std::vector<std::string> answers;
        int n = dictionary.size();

        for(int i = 0; i < n; ++i)
        {
            if(dictionary[i].length() > maxLength)
            {
                answers.clear();
                maxLength = dictionary[i].length();
                answers.push_back(dictionary[i]);
            }
            else if(dictionary[i].length() == maxLength)
            {
                answers.push_back(dictionary[i]);
            }
        }
        return answers;
    }
#endif

#if method2
    std::vector<std::string> longestWords(std::vector<std::string> &dictionary)
    {
        int n = dictionary.length();
        int m = dictionary[0].length();

        std::vector<std::string> s;
        s.push_back(dictionary[0]);

        for(int i = 1; i < n; ++i)
        {
            if(dictionary[i].length() > m)
            {
                s.clear();
                s.push_back(dictionary[i]);
                m = dictionary[i].length();
            }
            else if(dictionary[i].length() == m)
            {
                s.push_back(dictionary[i]);
            }
        }
        return s;
    }
#endif
};

int main(void)
{
    Solution s;
    std::vector<std::string> v = {"dog","google","facebook", "internationalization","blabla"};
    std::vector<std::string> v2;
    v2 = s.longestWords(v);

    std::cout << v2[0] << std::endl;
    return 0;
}
