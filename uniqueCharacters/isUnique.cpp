#include <iostream>
#include <vector>
#define method1 0
#define method2 0
#define method3 1


class Solution
{
public:
#if method1
    bool isUnique(std::string &str)
    {
        int ch[128] = {0};
        for(int i = 0; i < str.length(); ++i)
        {
            if(ch[str[i]] != 0)
            {
                return false;
            }
            else
            {
                ch[str[i]] = 1;
            }
        }

        return true;
    }
#endif

#if method2
    bool isUnique(std::string &str)
    {
        for(int i = 0; i < str.length(); ++i)
        {
            for(int j = i + 1; j < str.length(); ++j)
            {
                if(str[i] == str[j])
                {
                    return false;
                }
            }
        }

        return true;
    }
#endif

#if method3
    bool isUnique(std::string &str)
    {
        std::vector<int> table(256);
        for(char c : str)
        {
            if(table[c]++)
            {
                return false;
            }
        }

        return true;
    }
#endif
};

int main(void)
{
    Solution s;
    std::string str = "abc_____";
    bool result;

    result = s.isUnique(str);
    if(result)
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }

    return 0;
}
