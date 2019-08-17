#include <iostream>
using namespace std;
class Solution
{
public:
	long long trailingZeros(long long n)
	{
		long long count = 0;
		long long temp = n / 5;
		while(temp != 0)
		{
			count += temp;
			temp /= 5;
		}
		return count;
	}
};

int main()
{
	Solution s;
    long long m;
    cin >> m;
    cout << s.trailingZeros(m) << endl;
    return 0;
}
