#include <iostream>
#include <vector>
#define method1 0
#define method2 1


class Solution
{
public:
    //时间复杂度为O(n),空间复杂度为o(1)
#if method1
    int searchInsert(std::vector<int> &A, int target)
    {
        int index = 0;
        for(int i = 0; i < A.size(); ++i)
        {
            if(target <= A[i])
                return i;
            else
                index = i + 1;
        }
        return index;
    }
#endif

    //时间复杂度为O(log(n)),空间复杂度为o(1)
#if method2
    int searchInsert(std::vector<int> &A, int target)
    {
        int start = 0, end = A.size() - 1;
        while(start <= end)
        {
            if(A[start] > target)
                return start;
            if(A[end] < target)
                return end + 1;
            int mid = (start + end) >> 1;
            if(A[mid] == target)
                return mid;
            else if(A[mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
    }
#endif
};

int main()
{
    Solution s;
    std::vector<int> v {1, 3, 4, 6};
    int target = 6;
    std::cout << s.searchInsert(v, target) << std::endl;
    return 0;
}
