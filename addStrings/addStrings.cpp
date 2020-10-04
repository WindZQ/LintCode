#include <string>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    std::string addStrings(std::string &num1, std::string  num2)
    {
        std::string res = "";
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        while(i >= 0 || j >= 0)
        {
            int a = i >= 0 ? num1[i--] - '0' : 0;
            int b = j >= 0 ? num2[j--] - '0' : 0;
            int sum = a + b + carry;
            res.insert(res.begin(), sum % 10 + '0');
            carry = sum / 10;
        }
        return carry ? "1" + res : res;
    }
#endif

#if method2
    std::string addStrings(std::string &num1, std::string &num2)
    {
        int len1 = num1.length();
        int len2 = num2.length();
        int i, j;
        std::string res;
        std::string num = "0123456789";
        int sum, flag = 0;

        for(i = len1 - 1, j = len2 - 1; i >= 0 && j >= 0; --i, --j)
        {
            sum = (num1[i] - '0') + (num2[j] - '0') + flag;
            flag = sum / 10;
            sum %= 10;
            res += num[sum];
        }

        for(; i >= 0; --i)
        {
            sum = (num1[i] - '0') + flag;
            flag = sum / 10;
            sum %= 10;
            res += num[sum];
        }

        for(; j >= 0; --j)
        {
            sum = (num2[j] - '0') + flag;
            flag = sum / 10;
            sum %= 10;
            res += num[sum];
        }

        if(flag == 1)
        {
            res += "1";
        }
        std::reverse(res.begin(), res.end());

        return res;
    }
#endif
};
