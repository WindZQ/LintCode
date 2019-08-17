#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//方法一：直接排序
class Solution1 {
public:
    void recoverRotatedSortedArray(vector<int> &nums)
    {
        if(nums.size() == 0)
            return ;
        sort(nums.begin(), nums.end());
    }
};


//方法二：三步翻转法
class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums)
    {
        if(nums.size() == 0)
            return ;
        for(vector<int>::size_type index = 0; index < nums.size() - 1; ++index)
        {
            if(nums[index] > nums[index + 1])
            {
                reverse(nums, 0, index);
                reverse(nums, index + 1, nums.size() - 1);
                reverse(nums, 0, nums.size() - 1);
            }
        }
    }

    void reverse(vector<int> &num, vector<int>::size_type start, vector<int>:: size_type end)
    {
        for(vector<int>::size_type i = start, j = end; i < j; i++, j--)
        {
            int temp = num[i];
            num[i] = num[j];
            num[j] = temp;
        }
    }
};


int main()
{
    vector<int> v {4, 5, 1, 2, 3};
    Solution s;
    s.recoverRotatedSortedArray(v);
    for(int i = 0; i < v.size(); ++i)
        cout << v[i] << "\t";
    cout << endl;
    return 0;
}
