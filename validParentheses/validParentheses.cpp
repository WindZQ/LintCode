#include <vector>
#include <stack>
#include <string>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    bool isVaildParentheses(std::string &s)
    {
        std::vector<char> stack;
        stack.push_back(' ');

        for(int i = 0; i < s.size(); ++i)
        {
            char item = s[i];
            if(item == '(' || item == '[' || item == '{')
            {
                stack.push_back(item);
            }

            if(item == ')')
            {
                if(stack.back() != '(')
                {
                    return false;
                }
                stack.pop_back();
            }

            if(item == ']')
            {
                if(stack.back() != '[')
                {
                    return false;
                }
                stack.pop_back();
            }

            if(item == '}')
            {
                if(stack.back() != '{')
                {
                    return false;
                }
                stack.pop_back();
            }

            if(stack.back() != ' ')
            {
                return false;
            }
        }
        return true;
    }
#endif

#if method2
    bool isVaildParentheses(std::string &s)
    {
        std::stack<char> parentheses;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                parentheses.push(s[i]);
            }
            else
            {
                if(parentheses.empty()) return false;
                if(s[i] == ')' && parentheses.top() != '(') return false;
                if(s[i] == ']' && parentheses.top() != '[') return false;
                if(s[i] == '}' && parentheses.top() != '{') return false;
                parentheses.pop();
            }
        }
        return parentheses.empty();
    }
#endif
};
