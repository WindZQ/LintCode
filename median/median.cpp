#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define method1 0
#define method2 0
#define method3 1

class Solution
{
public:
    //时间复杂度为O(logn),空间复杂度为O(1)
#if method1
    int median(std::vector<int> &nums)
    {
        int k = (nums.size() + 1) >> 1, len = nums.size();
        std::priority_queue<int> q;
        for(int i = 0; i < len; ++i)
        {
            if(q.size() == k)
            {
                if(nums[i] < q.top())
                {
                    q.pop();
                    q.push(nums[i]);
                }
            }
            else
                q.push(nums[i]);
        }
        return q.top();
    }
#endif

    //时间复杂度为O(n), 空间复杂度为O(1)
#if method2
    void quickSort(std::vector<int> &s, int l, int r)
    {
        if(l < r)
        {
            int i = l, j = r, x = s[l];
            while(i < j)
            {
                while(i < j && s[j] >= x)
                    j--;
                if(i < j)
                    s[i++] = s[j];
                while(i < j && s[i] < x)
                    i++;
                if(i < j)
                    s[j--] = s[i];
            }
            s[i] = x;
            quickSort(s, l, i - 1);
            quickSort(s, i + 1, r);
        }
    }

    int median(std::vector<int> &nums)
    {
        int mid = nums.size() >> 1;
        quickSort(nums, 0, nums.size() - 1);
        if(nums.size() % 2 == 0)
            return nums[mid - 1];
        else
            return nums[mid];
    }
#endif

    //时间复杂度为O(nlogn),空间复杂度为O(1)
#if method3
    int median(std::vector<int> &nums)
    {
        int mid = nums.size() >> 1;
        std::sort(nums.begin(), nums.end());
        if(nums.size() % 2 == 0)
            return nums[mid - 1];
        else
            return nums[mid];
    }
#endif
};

int main()
{
    Solution s;
    std::vector<int> v {4, 5, 1, 2, 4};
    std::cout << s.median(v) << std::endl;
    return 0;
}
