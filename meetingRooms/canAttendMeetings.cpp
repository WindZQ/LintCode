#include <vector>
#include <algorithm>

#define method1 1
#define method2 0
#define method3 0

class Interval
{
    int start, end;
    Interval(int start, int end)
    {
        this->start = start;
        this->end = end;
    }
};

class Solution
{
public:
#if method1
    bool canAttendMeetings(std::vector<Interval> &intervals)
    {
        std::sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) { return a.start < b.start;});
        for(int i = 1; i < intervals.size(); ++i)
        {
            if(intervals[i].start < intervals[i - 1].end) return false;
        }

        return true;
    }
#endif

#if method2
    bool canAttendMeetings(std::vector<Interval> &intervals)
    {
        for(int i = 0; i < intervals.size(); ++i)
        {
            for(int j = i + 1; j < intervals.size(); ++j)
            {
                if((intervals[i].start >= intervals[j].start && intervals[i].start < intervals[j].end) || (intervals[j].start >= intervals[i].start && intervals[j].start < intervals[i].end)) return false;
            }
        }

        return true;
    }
#endif

#if method3
    static bool cmp(const Interval &v1, const Interval &v2)
    {
        return v1.start < v2.start;
    }

    bool canAttendMeetings(std::vector<Interval> &intervals)
    {
        std::sort(intervals.begin(), intervals.end(), cmp);
        int end = -1;
        for(int i = 0; i < intervals.size(); ++i)
        {
            if(intervals[i].start < end) return false;
            end = std::max(end, intervals[i].end);
        }

        return true;
    }
#endif
};
