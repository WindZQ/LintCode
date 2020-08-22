#include <vector>
#include <set>

#define method1 1
#define method2 0
#define method3 0
#define method4 0

class Solution
{
public:
#if method1
    std::vector<int> intersection(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::set<int> s(nums1.begin(), nums1.end()), res;
        for(auto a : nums2)
        {
            if(s.count(a))
            {
                res.insert(a);
            }
        }

        return std::vector<int>(res.begin(), res.end());
    }
#endif

#if method2
    std::vector<int> intersection(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::vector<int> res;
        int i = 0, j = 0;
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] < nums2[j])
            {
                ++i;
            }
            else if(nums1[i] > nums2[j])
            {
                ++j;
            }
            else
            {
                if(res.empty() || res.back() != nums1[i])
                {
                    res.push_back(nums1[i]);
                }
                ++i;
                ++j;
            }
        }

        return res;
    }
#endif

#if method3
    std::vector<int> intersection(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::set<int> res;
        std::sort(nums2.begin(), nums2.end());

        for(auto a : nums1)
        {
            if(binary_search(nums2, a))
            {
                res.insert(a);
            }
        }

        return std::vector<int>(res.begin(), res.end());
    }

    bool binary_search(std::vector<int> &nums, int target)
    {
        int left = 0, right = nums.size();
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target)
            {
                return true;
            }
            else if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return false;
    }
#endif

#if method4
    std::vector<int> intersection(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end()), res;
        std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(res, res.begin()));
        return std::vector<int>(res.begin(), res.end());
    }
#endif
};
