#include <math>

class Solution
{
public:
	int subSum(int n)
	{
		int sum = 0;
		for(int i = 1; i <= n; ++i)
		{
			sum += i;
		}
		
		return sum * pow(2, n - 1);
	}
};