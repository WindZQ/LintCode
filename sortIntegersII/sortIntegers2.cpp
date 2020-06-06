#include <vector>
#include <algorithm>

#define method1 1
#define method1 0

class Solution
{
public:
#if method1
    void sortIntegers2(std::vector<int>  &A)
    {
        quick_sort(A, 0, A.size() - 1);
    }

    void quick_sort(std::vector<int> &A, int start, int end)
    {
        if(start >= end) return;
        int pos = partition(A, start, end);
        quick_sort(A, start, pos - 1);
        quick_sort(A, pos, end);
    }

    int partition(std::vector<int> &A, int start, int end)
    {
        int i = start, j = end, pivot = A[(start + end) >> 1];
        while(i <= j)
        {
            while(i <= j && A[i] < pivot) ++i;
            while(i <= j && A[j] > pivot) --j;
            if(i <= j)
            {
                std::swap(A[i], A[j]);
                ++i;
                --j;
            }
        }

        return i;
    }
#endif

#if method2
    void sortIntegers2(std::vector<int> &A)
    {
        quick_sort(A, 0, A.size() - 1);
    }

    void quick_sort(std::vector<int> &A, int start, int end)
    {
        if(start >= end) return;
        int pos = partition(A, start, end);
        quick_sort(A, start, pos - 1);
        quick_sort(A, pos, end);
    }

    int partition(std::vector<int> &A, int start, int end)
    {
        int i = start - 1, pivot = A[end];
        for(int j = start; j < end; ++j)
        {
            if(A[j] <= pivot)
            {
                ++i;
                std::swap(A[i], A[j]);
            }
        }

        std::swap(A[i + 1], A[end]);
        return i + 1;
    }
#endif
};
