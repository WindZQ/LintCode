#include <unordered_set>


#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
    bool isHappy(int n)
    {
        unordered_set<int> st;
        while(n != 1)
        {
            int sum = 0;
            while(n)
            {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            n = sum;
            if(st.count(n)) break;
            st.insert(n);
        }
        return n == 1;
    }
#endif

#if method2
    bool isHappy(int n)
    {
        while(n != 1 && n != 4)
        {
            int sum = 0;
            while(n)
            {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
#endif

#if method3
    bool isHappy(int n)
    {
        int slow = n, fast = n;
        while(true)
        {
            slow = find_next(slow);
            fast = find_next(fast);
            fast = find_next(fast);
            if(slow == fast) break;
        }
        return slow == 1;
    }

    int find_next(int n)
    {
        int res = 0;
        while(n > 0)
        {
            res += (n % 10) * (n % 10);
            n /= 10;
        }
        return res;
    }
#endif
};
