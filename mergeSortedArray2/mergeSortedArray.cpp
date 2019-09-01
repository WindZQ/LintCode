#include <iostream>
#define method1 1
#define method2 0

class Solution
{
public:
    //时间复杂度为O(n),空间复杂度为O(1)
#if method1
    void mergeSortedArray(int A[], int m, int B[], int n)
    {
        int i = m - 1, j = n - 1, index = m + n - 1;
        while(i >=0 && j >= 0)
            A[index--] = A[i] > B[j] ? A[i--] : B[j--];
        while(i >= 0)
            A[index--] = A[i--];
        while(j >= 0)
            A[index--] = B[j--];
    }
#endif

    //时间复杂度为O(n), 空间复杂度为O(1)
#if method2
    void mergeSortedArray(int A[], int m, int B[], int n)
    {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while(j >= 0)
            A[k--] = i >=0 && A[i] > B[j] ? A[i--] : B[j--];
    }
#endif
};

int main()
{
    Solution s;
    int a[] = {1, 2, 5}, m = 3;
    int b[] = {3, 4}, n = 2;
    s.mergeSortedArray(a, m, b, n);
    for(int i = 0;i < m + n; ++i)
        printf("%d\t", a[i]);
    return 0;
}
