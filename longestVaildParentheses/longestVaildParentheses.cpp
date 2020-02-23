#include <iostream>
#include <string>
#include <stack>
#include <vector>

#define method1 0
#define method2 0
#define method3 1


class Solution
{
public:
#if method1
    int longestVaildParentheses(std::string &s)
    {
        int res = 0, start = 0, n = s.size();
        std::stack<int> st;
        for(int i = 0; i < n; ++i)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            else if(s[i] == ')')
            {
                if(st.empty())
                {
                    start = i + 1;
                }
                else
                {
                    st.pop();
                    res = st.empty() ? std::max(res, i - start + 1) : std::max(res, i - st.top());
                }
            }
        }
        return res;
    }
#endif

#if method2
    int longestVaildParentheses(std::string &s)
    {
        int res = 0, n = s.size();
        std::vector<int> dp(n + 1);

        for(int i = 1; i <= n; ++i)
        {
            int j = i - 2 - dp[i - 1];
            if(s[i - 1] == '(' || j < 0 || s[j] == ')')
            {
                dp[i] = 0;
            }
            else
            {
                dp[i] = dp[i - 1] + 2 + dp[j];
                res = std::max(res, dp[i]);
            }
        }
        return res;
    }
#endif

#if method3
    int longestVaildParentheses(std::string &s)
    {
        int res = 0, left = 0, right = 0, n = s.size();

        for(int i = 0; i < n; ++i)
        {
            (s[i] == '(') ? ++left : ++right;
            if(left == right)
            {
                res = std::max(res, 2 * right);
            }
            else if(right > left)
            {
                left = right = 0;
            }
        }
        left = right = 0;
        for(int i = n - 1; i >= 0; --i)
        {
            (s[i] == '(') ? ++left : ++right;
            if(left == right)
            {
                res = std::max(res, 2 * right);
            }
            else if(left > right)
            {
                left = right = 0;
            }
        }
        return res;
    }
#endif
};

int main(void)
{
    Solution s;
    std::string str = ")()())";
    std::cout << "The result: " << s.longestVaildParentheses(str) << std::endl;

    return 0;
}
