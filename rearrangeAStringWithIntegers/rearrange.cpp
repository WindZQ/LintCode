#include <string>
#include <algorithm>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
	std::string rearrange(std::string &str)
	{
		std::sort(str.begin(), str.end());
		int result = 0;
		int index = -1;
		
		for(int i = 0;i < str.size(); ++i)
		{
			if(str[i] >= '0' && str[i] <= '9')
			{
				result += str[i] - '0';
				index++;
			}
			else
			{
				break;
			}
		}
		
		if(index == -1)
		{
			return str;
		}
		else 
		{
			std::string ans = str.substr(index + 1);
			ans += to_string(result);
			return ans;
		}
	}
#endif

#if method2
	std::string rearrange(std::string &str)
	{
		std::sort(str.begin(), str.end());
		int sum = 0, i = 0;
		for(; i < str.size() && isdigit(str[i]); ++i)
		{
			sum += str[i] - '0';
		}
		
		if(i)
		{
			return str.substr(i) + to_string(sum);
		}
		
		return str;
	}
#endif
};