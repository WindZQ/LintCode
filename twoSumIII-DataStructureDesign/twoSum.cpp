#include <unordered_set>
#include <unordered_map>
#include <vector>

#define method1 1
#define method2 0
#define method3 0

class TwoSum
{
public:
#if method1
    std::unordered_multiset<int> nums;
    void add(int number)
    {
        nums.insert(number);
    }

    bool find(int value)
    {
        for(int i : nums)
        {
            int count = i == value - i ? 2 : 1;
            if(nums.count(value - i) >= count)
            {
                return true;
            }
        }

        return false;
    }
#endif

#if method2
    std::unordered_map<int, unordered_set<int>> m;
    int cnt = 0;
    void add(int number)
    {
        m[number].insert(++cnt);
    }

    bool find(int value)
    {
        for(auto e : m)
        {
            if(m.count(value - e.first) && e.first * 2 != value)
            {
                return true;
            }
            if(e.first * 2 == value && m[e.first].size() >= 2)
            {
                return true;
            }
        }
        return false;
    }
#endif

#if method3
    std::vector<int> arr;
    void add(int number)
    {
        arr.push_back(number);
    }

    bool find(int value)
    {
        if(arr.size() == 0)
        {
            return false;
        }

        if(arr.size() == 1)
        {
            if(arr[0] == value)
            {
                return true;
            }
            return false;
        }
        std::sort(arr.begin(), arr.end());
        int left = 0, right = arr.size() - 1;
        while(left < right)
        {
            if(arr[left] + arr[right] == value)
            {
                return true;
            }
            if(arr[left] + arr[right] < value)
            {
                left++;
                continue;
            }
            right--;
        }
        return false;
    }
#endif
};
