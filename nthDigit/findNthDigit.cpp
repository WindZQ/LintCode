#include <string>
#include <math>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    int findNthDigit(int n)
    {
        long long len = 1, cnt = 9, start = 1;
        while(n > len * cnt)
        {
            n -= len * cnt;
            ++len;
            cnt *= 10;
            start *= 10;
        }

        start += (n - 1) / len;
        std::string t = to_string(start);
        return t[(n - 1) % len] - '0';
    }
#endif

#if method2
    int findNthDigit(int n)
    {
        int low = 1, high = 9;
        while(low < high)
        {
            int mid = (high - low) / 2 + low;
            if(total_digit(mid) < n)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }

        int d = low;
        int prev_digits = total_digit(d - 1);
        int index = n - prev_digits - 1;
        int start = (int)pow(10, d - 1);
        int num = start + index / d;
        int digit_index = index % d;
        int digit = (num / (int)(pow(10, d - digit_index - 1))) % 10;

        return digit;
    }

    int total_digit(int length)
    {
        int digits = 0;
        int cur_length = 1, cur_count = 9;
        while(cur_length <= length)
        {
            digits += cur_length * cur_count;
            cur_length++;
            cur_count *= 10;
        }

        return digits;
    }
#endif
};
