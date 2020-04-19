#include <iostream>
#include <string>
#include <algorithm>

#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
    std::string addBinary(std::string &a, std::string &b)
    {
        std::string result;
        std::size_t n = a.size() > b.size() ? a.size() : b.size();
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());
        int carry = 0;
        for(size_t i = 0; i < n; ++i)
        {
            int ai = i < a.size() ? a[i] - '0' : 0;
            int bi = i < b.size() ? b[i] - '0' : 0;
            int val = (ai + bi + carry) % 2;
            carry = (ai + bi + carry) / 2;
            result.insert(result.begin(), val + '0');
        }
        if(carry == 1)
        {
            result.insert(result.begin(), '1');
        }
        return result;
    }
#endif

#if method2
    std::string addBinary(std::string &a, std::string &b)
    {
        std::string res;
        int na = a.size(), nb = b.size();
        int n = std::max(na, nb);
        bool carry = false;
        if(na > nb)
        {
            for(int i = 0; i < na - nb; ++i)
            {
                b.insert(b.begin(), '0');
            }
        }
        else if(na < nb)
        {
            for(int i = 0; i < nb - na; ++i)
            {
                a.insert(a.begin(), '0');
            }
        }

        for(int i = n - 1; i >= 0; --i)
        {
            int tmp = 0;
            if(carry)
            {
                tmp = (a[i] - '0') + (b[i] - '0') + 1;
            }
            else
            {
                tmp = (a[i] - '0') + (b[i] - '0');
            }
            if(tmp == 0)
            {
                res.insert(res.begin(), '0');
                carry = false;
            }
            else if(tmp == 1)
            {
                res.insert(res.begin(), '1');
                carry = false;
            }
            else if(tmp == 2)
            {
                res.insert(res.begin(), '0');
                carry = true;
            }
            else if(tmp == 3)
            {
                res.insert(res.begin(), '1');
                carry = true;
            }
        }
        if(carry)
        {
            res.insert(res.begin(), '1');
        }
        return res;
    }
#endif

#if method3
    std::string addBinary(std::string &a, std::string &b)
    {
        std::string res = "";
        int m = a.size() - 1, n = b.size() - 1, carry = 0;
        while(m >= 0 || n >= 0)
        {
            int p = m >= 0 ? a[m--] - '0' : 0;
            int q = n >= 0 ? b[n--] - '0' : 0;
            int sum = p + q + carry;
            res = std::to_string(sum % 2) + res;
            carry = sum / 2;
        }
        return carry == 1 ? "1" + res : res;
    }
#endif
};
