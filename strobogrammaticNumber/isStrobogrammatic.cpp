#include <string>
#include <unordered_map>

#define method1 1
#define method2 0


class Solution
{
public:
#if method1
    bool isStrobogrammatic(std::string &num)
    {
        int left = 0, right = num.size() - 1;
        while(left <= right)
        {
            if(num[left] == num[right])
            {
                if(num[left] != '1' && num[left] != '0' && num[right] != '8')
                {
                    return false;
                }
            }
            else
            {
                if((num[left] != '6' || num[right] != '9') && (num[left] != '9' || num[right] != '6'))
                {
                    return false;
                }
            }
            ++left;
            --right;
        }
        return true;
    }
#endif

#if method2
    bool isStrobogrammatic(std::string &num)
    {
        unordered_map<char, char> m {{'0', '0'}, {'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};
        for (int i = 0; i <= num.size() / 2; ++i)
        {
            if (m[num[i]] != num[num.size() - i - 1])
            {
                return false;
            }
        }
        return true;
    }
#endif
};
