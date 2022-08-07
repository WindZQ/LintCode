#include <vector>
#include <unordered_set>
#include <algorithm>

#define method1 1
#define method2 0


class Solution
{
public:
#if method1
    std::vector<int> fairCandySwap(std::vector<int> &a, std::vector<int> &b)
    {
        std::vector<int> res;
        int a_sum = 0, b_sum = 0;

        for (auto &x : a)
        {
            a_sum += x;
        }

        for (auto &x : b)
        {
            b_sum += x;
        }

        int delta = (b_sum - a_sum) / 2;
        std::unordered_set<int> s(b.begin(), b.end());

        for (auto &x : a)
        {
            if (s.find(x + delta) != s.end())
            {
                res.push_back(x);
                res.push_back(x + delta);
                break;
            }
        }

        return res;
    }
#endif

#if method2
    std::vector<int> fairCandySwap(std::vector<int> &a, std::vector<int> &b)
    {
        std::vector<int> res;
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());

        int a_sum = 0, b_sum = 0;
        for (auto &x : a)
        {
            a_sum += x;
        }

        for (auto &x : b)
        {
            b_sum += x;
        }

        for (int i = 0; i < a.size(); ++i)
        {
            int alice = a_sum - a[i];
            int bob = b_sum + a[i];

            int val = (bob - alice) / 2;
            int index = search(b, val);

            if (index != -1)
            {
                res.push_back(a[i]);
                res.push_back(b[index]);
                return res;
            }
        }
        return res;
    }

    int search(std::vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return -1;
    }
#endif
};
