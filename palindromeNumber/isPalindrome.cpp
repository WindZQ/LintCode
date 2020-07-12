#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
    bool isPalindrome(int num)
    {
        if(num < 0) return false;
        int div = 1;
        while(num / div >= 10) div *= 10;
        while(num > 0)
        {
            int left = num / div;
            int right = num % 10;
            if(left != right) return false;
            num = (num % div) / 10;
            div /= 100;
        }
        return true;
    }
#endif

#if method2
    bool isPalindrome(int num)
    {
        if(num < 0 || (num % 10 == 0 && num != 0))
        {
            return false;
        }
        return reverse(num) == num;
    }

    int reverse(int num)
    {
        int res = 0;
        while(num != 0)
        {
            if(res > INT_MAX / 10) return -1;
            res = res * 10 + num % 10;
            num /= 10;
        }
        return res;
    }
#endif

#if method3
    bool isPalindrome(int num)
    {
        if(num < 0 || (num % 10 == 0 && num != 0))
        {
            return false;
        }

        int reverse_num = 0;
        while(num > reverse_num)
        {
            reverse_num = reverse_num * 10 + num % 10;
            num /= 10;
        }
        return num == reverse_num || num == reverse_num / 10;
    }
#endif
}
