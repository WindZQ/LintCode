#include <iostream>
#include <vector>
#include <cmath>

class Solution
{
public:
	double cosineSimilarity(std::vector<int> A, std::vector<int> B)
	{
		int factor = 0;
		for(int i = 0; i < A.size(); ++i)
		{
			factor += A[i] * B[i];
		}
		
		int sumA = 0;
		for(int i = 0; i < A.size(); ++i)
		{
			sumA += A[i] * A[i];
		}
		
		int sumB = 0;
		for(int i = 0; i < B.size(); ++i)
		{
			sumB += B[i] * B[i];
		}
		
		if(sumA == 0 || sumB == 0)
		{
			return 2;
		}
		
		return factor / sqrt(sumA) / sqrt(sumB);
	}
}