#include <vector>
#include <unordered_map>
#include <stack>

#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
    std::vector<int> nextGreaterElement(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::vector<int> res(nums1.size());

        for(int i = 0; i < nums1.size(); ++i)
        {
            int j = 0, k = 0;
            for(; j < nums2.size(); ++j)
            {
                if(nums2[j] == nums1[i]) break;
            }

            for(k = j + 1; k < nums2.size(); ++k)
            {
                if(nums2[k] > nums2[j])
                {
                    res[i] = nums2[k];
                    break;
                }
            }

            if(k == nums2.size()) res[i] = -1;
        }

        return res;
    }
#endif

#if method2
    std::vector<int> nextGreaterElement(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::vector<int> res(nums1.size());
        std::unordered_map<int, int> m;

        for(int i = 0; i < nums2.size(); ++i)
        {
            m[nums2[i]] = i;
        }

        for(int i = 0; i < nums1.size(); ++i)
        {
            res[i] = -1;
            int start = m[nums1[i]];
            for(int j = start + 1; j < nums2.size(); ++j)
            {
                if(nums2[j] > nums1[i])
                {
                    res[i] = nums2[j];
                    break;
                }
            }
        }

        return res;
    }
#endif

#if method3
    std::vector<int> nextGreaterElement(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::vector<int> res;
        std::stack<int> st;
        std::unordered_map<int, int> m;

        for(int num : nums2)
        {
            while(!st.empty() && st.top() < num)
            {
                m[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        for(int num : nums1)
        {
            res.push_back(m.count(num) ? m[num] : -1);
        }

        return res;
    }
#endif
};
