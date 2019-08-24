#include <iostream>
#include <string>
#include <algorithm>
#define method1 0
#define method2 1
#define method3 0


class Solution
{
public:
#if method1
    //时间复杂度为O(nlogn), 空间复杂度为O(n)
    std::string reverseWords(std::string &s)
    {
        std::reverse(s.begin(), s.end());
        int index = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] != ' ')
            {
                if(index != 0) s[index++] = ' ';
                int j = i;
                while(j < s.size() && s[j] != ' ')
                    s[index++] = s[j++];
                reverse(s.begin() + index - (j - i), s.begin() + index);
                i = j;
            }
        }
        s.resize(index);
        return s;
    }
#endif

#if method2
    //时间复杂度为O(n), 空间复杂度为O(1)
    std::string reverseWords(std::string &s)
    {
        std::istringstream is(s);
        std::string tmp;
        is >> s;
        while(is >> tmp)
            s = tmp + " " + s;
        if(!s.empty() && s[0] == ' ')
            s = "";
        return s;
    }
#endif

#if method3
    //时间复杂度为O(n), 空间复杂度为O（1）
    std::string reverseWords(std::string &s)
    {
        std::istringstream is(s);
        s = "";
        std::string tmp = "";
        while(getline(is, tmp, ' '))
        {
            if(tmp.empty())
                continue;
            s = (s.empty()) ? tmp :(tmp + " "+ s);
        }
        return s;
    }
#endif
};

int main()
{
    Solution s;
    std::string str = " Hello World ";
    std::cout << s.reverseWords(str) << std::endl;
    return 0;
}
