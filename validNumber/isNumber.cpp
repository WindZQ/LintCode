#include <iostream>
#include <string>

#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
	bool isNumber(std::string &s)
	{
		bool num = false, numAfterE = true, dot = false, exp = false, sign = false;
        int n = s.size();
        for (int i = 0; i < n; ++i) 
		{
            if (s[i] == ' ') 
			{
                if (i < n - 1 && s[i + 1] != ' ' && (num || dot || exp || sign)) 
					return false;
            } 
			else if (s[i] == '+' || s[i] == '-') 
			{
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != ' ') 
					return false;
                sign = true;
            } 
			else if (s[i] >= '0' && s[i] <= '9') 
			{
                num = true;
                numAfterE = true;
            } 
			else if (s[i] == '.') 
			{
                if (dot || exp) 
					return false;
                dot = true;
            } else if (s[i] == 'e') 
			{
                if (exp || !num) 
					return false;
                exp = true;
                numAfterE = false;
            } 
			else 
				return false;
        }
        return num && numAfterE;
	}
#endif

#if method2
	bool isNumber(std::string &s)
	{
		int len = s.size();
        int left = 0, right = len - 1;
        bool eExisted = false;
        bool dotExisted = false;
        bool digitExisited = false;
		
        while (s[left] == ' ') 
			++left;
        while (s[right] == ' ') 
			--right;
		
        if (left >= right && (s[left] < '0' || s[left] > '9')) 
			return false;
     
        if (s[left] == '.') 
			dotExisted = true;
        else if (s[left] >= '0' && s[left] <= '9') 
			digitExisited = true;
        else if (s[left] != '+' && s[left] != '-') 
			return false;
		
        for (int i = left + 1; i <= right - 1; ++i) 
		{
            if (s[i] >= '0' && s[i] <= '9') 
				digitExisited = true;
            else if (s[i] == 'e' || s[i] == 'E') 
			{ 
                if (!eExisted && s[i - 1] != '+' && s[i - 1] != '-' && digitExisited) 
					eExisted = true;
                else return false;
            } 
			else if (s[i] == '+' || s[i] == '-') 
			{ 
                if (s[i - 1] != 'e' && s[i - 1] != 'E') 
					return false;                
            } 
			else if (s[i] == '.') 
			{ 
                if (!dotExisted && !eExisted) 
					dotExisted = true;
                else 
					return false;
            } else 
				return false;
        }
    
        if (s[right] >= '0' && s[right] <= '9') 
			return true;
        else if (s[right] == '.' && !dotExisted && !eExisted && digitExisited) 
			return true;
        else 
			return false;
	}
#endif

#if method3
	bool isNumber(std::string &s)
	{
		enum InputType
        {
            INVALID,   
            SPACE,     
            SIGN,      
            DIGIT,     
            DOT,       
            EXPONENT,  
            NUM_INPUTS 
        };
		
        const int transitionTable[][NUM_INPUTS] = 
		{
            -1, 0, 3, 1, 2, -1,    
            -1, 8, -1, 1, 4, 5,    
            -1, -1, -1, 4, -1, -1, 
            -1, -1, -1, 1, 2, -1,  
            -1, 8, -1, 4, -1, 5,  
            -1, -1, 6, 7, -1, -1,  
            -1, -1, -1, 7, -1, -1, 
            -1, 8, -1, 7, -1, -1,  
            -1, 8, -1, -1, -1, -1, 
        };

        int state = 0;
        for (const char c : s)
        {
            InputType inputType = INVALID;
            if (isspace(c))
                inputType = SPACE;
            else if (c == '+' || c == '-')
                inputType = SIGN;
            else if (isdigit(c))
                inputType = DIGIT;
            else if (c == '.')
                inputType = DOT;
            else if (c == 'e' || c == 'E')
                inputType = EXPONENT;

            state = transitionTable[state][inputType];

            if (state == -1)
                return false;
        }

        return state == 1 || state == 4 || state == 7 || state == 8;
	}
#endif
	
};