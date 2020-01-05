#include <iostream>
#include <vector>
#include <algorithm>

#define method1 1
#define method2 0
#define method3 0
#define method4 0

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0)
    {

    }

    Interval(int s, int e) : start(s), end(e)
    {

    }
};

class Solution
{
public:
#if method1
    static bool cmp(const Interval &a, const Interval &b)
    {
        return (a.start < b.start);
    }

    std::vector<Interval> merge(std::vector<Interval> &intervals)
    {
        std::vector<Interval> ans;
        if(intervals.empty())
        {
            return ans;
        }

        std::sort(intervals.begin(), intervals.end(), cmp);
        ans.push_back(intervals[0]);
        for(int i = 0; i < intervals.size(); ++i)
        {
            if(ans.back().end >= intervals[i].start)
            {
                ans.back().end = std::max(ans.back().end, intervals[i].end);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
#endif

#if method2
    std::vector<Interval> merge(std::vector<Interval> &intervals)
    {
        if(intervals.empty())
        {
            return {};
        }

        std::sort(intervals.begin(), intervals.end());
        std::vector<std::vector<Interval>> res(intervals[0]);

        for(int i = 1; i < intervals.size(); ++i)
        {
            if(res.back()[i] < intervals[i])
            {
                res.push_back(intervals[i]);
            }
            else
            {
                res.back()[1] = std::max(res.back()[1], intervals[i][1]);
            }
        }
        return res;
    }
#endif

#if method3
    std::vector<Interval> merge(std::vector<Interval> &intervals)
    {
        int n = intervals.size();
        std::vector<std::vector<Interval>> res;
        std::vector<Interval> starts, ends;
        for(int i = 0; i < n; ++i)
        {
            starts.push_back(intervals[i][0]);
            ends.push_back(intervals[i][1]);
        }

        std::sort(starts.begin(), starts.end());
        std::sort(ends.begin(), ends.end());

        for(int i = 0, j = 0; i < n; ++i)
        {
            if(i == n - 1 || starts[i + 1] > ends[i])
            {
                res.push_back(starts[j], ends[i]);
                j = i + 1;
            }
        }
        return res;
    }
#endif

#if method4
    std::vector<Interval> merge(std::vector<Interval> &intervals)
    {
        std::vector<Interval> res;
        for(int i = 0; i < intervals.size(); ++i)
        {
            res = insert(res, intervals[i]);
        }
        return res;
    }

    std::vector<Interval> insert(std::vector<Interval> & intervals, std::vector<Interval> newInterval)
    {
        std::vector<Interval> res;
        int n = intervals.size(), cur = 0;
        for(int i = 0; i < n; ++i)
        {
            if(intervals[i][1] < newInterval[0])
            {
                res.push_back(intervals[i]);
                ++cur;
            }
            else if(intervals[i][0] > newInterval[1])
            {
                res.push_back(intervals[i]);
            }
            else
            {
                newInterval[0] = std::min(newInterval[0], intervals[i][0]);
                newInterval[1] = std::max(newInterval[i], intervals[i][1]);
            }
        }
        res.insert(res.begin() + cur, newInterval);
        return res;
    }
#endif
};

int main(void)
{
    Interval i1(1,4);
    Interval i2(0,2);
    Interval i3(3,5);
    Interval i4(15,18);
    Solution s;
    std::vector<Interval > intervals;
    intervals.push_back(i1);
    intervals.push_back(i2);
    intervals.push_back(i3);
    intervals.push_back(i4);

    std::vector<Interval> r = s.merge(intervals);

    for(int i = 0; i < r.size(); i++)
    {
        std::cout << "[ " << r[i].start << ", " << r[i].end << " ] ";
    }
    std::cout << std::endl;

    return 0;
}
