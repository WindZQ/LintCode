#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Soluction
{
public:
    //方法一：
	vector<int> mergeSortedArray(vector<int> &A, vector<int> &B)
	{
		copy(B.begin(), B.end(), back_inserter(A));
		sort(A.begin(), A.end());
		return a;
	}
	
	//方法二：
	vector<int> mergeSortedArray1(vector<int> &A, vector<int> &B)
	{
		for(vector<int>::iterator it = B.begin(); it != B.end(); ++it)
			A.push_back(*it);
		sort(A.begin(), A.end());
		return A;
	}
	
};

int main()
{
	Soluction s;
    vector<int> A = {1, 2, 3};
    vector<int> B = {2, 3, 5};
    s.mergeSortedArray(A, B);
    for(vector<int>::iterator it = A.begin(); it != A.end(); ++it)
        cout << *it << endl;
    return 0;
}
