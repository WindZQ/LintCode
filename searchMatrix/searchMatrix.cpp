#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	//方法一：
	bool searchMatrix(vector<vector<int>> &matrix, int target)
	{
	    for(int i = 0;i < matrix.size(); ++i)
	    {
	        for(int j = 0; j < matrix[0].size(); ++j)
	        {
	            if(matrix[i][j] == target)
	                return true;
	        }
	    }
	    return false;
	}

	//方法二：
	bool searchMatrix(vector<vector<int>> &matrix, int target)
	{
	    int i = 0, j = matrix[0].size() - 1;
	    while(i < matrix.size() && j >= 0)
	    {
	        if(matrix[i][j] == target)
	            return true;
	        else if(matrix[i][j] < target)
	            i++;
	        else
	            j--;
	    }
	    return false;
	}

	//方法三：
	bool searchMatrix(vector<vector<int>> &matrix, int target)
	{
		int row = matrix.size();
		int col = matrix[0].size();
		int l = 0, r = row * col;
		while(l < r)
		{
			int mid = l + ((r - l) >> 1);
			if(matrix[mid / col][mid % col] == target)
				return true;
			else if(matrix[mid / col][mid % col] < target)
				l = mid + 1;
			else
				r = mid;
		}
    return false;
	}
};

int main()
{
	Solution s;
    vector<vector<int>> matrix {{1, 2, 3},{4, 5, 6}};
    int target = 6;
    if(s.searchMatrix(matrix, target))
        cout << "True!" << endl;
    else
        cout << "False!" << endl;
    return 0;
}
