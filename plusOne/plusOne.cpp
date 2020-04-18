#include <iostream>
#include <vector>

#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
    std::vector<int> plusOne(std::vector<int> &digits)
    {
        int c = 1;
        for(auto it = digits.rbegin(); it != digits.rend(); ++it)
        {
            *it += c;
            c = *it / 10;
            *it %= 10;
        }
        if(c > 0) digits.insert(digits.begin(), 1);
        return digits;
    }
#endif

#if method2
    std::vector<int> plusOne(std::vector<int> &digits)
    {
        int n = digits.size();
        for(int i = n - 1; i >= 0; --i)
        {
            if(digits[i] == 9) digits[i] = 0;
            else
            {
                digits[i] += 1;
                return digits;
            }
        }
        if(digits.front() == 0) digits.insert(digits.begin(), 1);
        return digits;
    }
#endif

#if method3
    std::vector<int> plusOne(std::vector<int> &digits)
    {
        if(digits.empty()) return digits;
        int carry = 1, n = digits.size();
        for(int i = n - 1; i >= 0; --i)
        {
            if(carry == 0) return digits;
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        if(carry == 1) digits.insert(digits.begin(), 1);
        return digits;
    }
#endif
};
