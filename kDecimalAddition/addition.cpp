#include <string>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    std::string addition(int k, std::string &a, std::string &b)
    {
        int o = 0, i = a.size() - 1, j = b.size() - 1;
        std::string result;

        for (; i >= 0 || j >= 0 || o; --i, --j)
        {
            auto r = o;

            if (i >= 0)
            {
                r += a[i] - '0';
            }

            if (j >= 0)
            {
                r += b[j] - '0';
            }

            result += r % k + '0';
            o = r / k;
        }

        auto item = result.rbegin();
        while (item != result.rend())
        {
            if (*item == '0')
            {
                item++;
            }
            else
            {
                return std::string(item, result.rend());
            }
        }

        return "0";
    }
#endif

#if method2
    std::string addition(int k, std::string &a, std::string &b)
    {
        int temp = 0;

        for (int i = 0; i < a.size(); ++i)
        {
            if (a[i] != '0')
            {
                a = a.substr(i);
                break;
            }
        }

        for (int i = 0; i < b.size(); ++i)
        {
            if (b[i] != '0')
            {
                b = b.substr(i);
                break;
            }
        }

        if (a.size() < b.size())
        {
            std::swap(a, b);
        }

        int j = b.size() - 1;
        for (int i = a.size() - 1; i >= 0; i--)
        {
            int sum = a[i] - '0';
            if (j >= 0)
            {
                sum += b[j] - '0';
                j--;
            }

            if (temp != 0)
            {
                sum += temp;
            }

            a[i] = '0' + sum % k;
            temp = sum / k;
        }

        std::string res;
        if (temp != 0)
        {
            res.push_back(temp + '0');
        }

        res = res + a;

        return res;
    }
#endif
};
