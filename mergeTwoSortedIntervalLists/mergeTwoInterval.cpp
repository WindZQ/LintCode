#include <vector>

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
    std::vector<Interval> mergeTwoInterval(std::vector<Interval> &list1, std::vector<Interval> &list2)
    {
        if(list1.size() == 0) return list2;
        if(list2.size() == 0) return list1;

        int index1 = 0, index2 = 0;
        Interval now;
        std::vector<Interval> res;

        while(index1 < list1.size() && index2 < list2.size())
        {
            Interval a = list1[index1], b = list2[index2];

            if(a.start <= b.start)
            {
                now = a;
                index1++;
            }
            else
            {
                now = b;
                index2++;
            }

            if(res.empty())
            {
                res.push_back(now);
            }
            else
            {
                Merge(res, res[res.size() - 1], now);
            }
        }

        while(index2 < list2.size())
        {
            Merge(res, res[res.size() - 1], list2[index2++]);
        }

        while(index1 < list1.size())
        {
            Merge(res, res[res.size() - 1], list1[index1++]);
        }

        return res;
    }

    void Merge(std::vector<Interval> &res, Interval &last, Interval &now)
    {
        if(last.end < now.start)
        {
            res.push_back(now);
        }
        else
        {
            last.end = std::max(last.end, now.end);
        }
    }
#endif

#if method2
    std::vector<Interval> mergeTwoInterval(std::vector<Interval> &list1, std::vector<Interval> &list2)
    {
        std::vector<Interval> res;
        int index1 = 0, index2 = 0;
        while(index1 < list1.size() && index2 < list2.size())
        {
            if(list1[index1].start < list2[index2].start)
            {
                pushBack(list1[index1], res);
                index1++;
            }
            else
            {
                pushBack(list2[index2], res);
                index2++;
            }
        }

        while(index1 < list1.size())
        {
            pushBack(list1[index1], res);
            index1++;
        }

        while(index2 < list2.size())
        {
            pushBack(list2[index2], res);
            index2++;
        }

        return res;
    }

    void pushBack(Interval &interval, std::vector<Interval> &res)
    {
        if(res.empty())
        {
            res.push_back(interval);
            return ;
        }

        if(interval.start > res.back().end)
        {
            res.push_back(interval);
            return;
        }

        res.back().end = std::max(res.back().end, interval.end);
    }
#endif

#if method3
    std::vector<Interval> mergeTwoInterval(std::vector<Interval> &list1, std::vector<Interval> &list2)
    {
        std::vector<Interval> res;
        helper(res, list1, 0, list2, 0);
        return res;
    }

    void helper(std::vector<Interval> &res, std::vector<Interval> &list1, int index1, std::vector<Interval> &list2, int index2)
    {
        if(index1 == list1.size() && index2 == list2.size()) return;
        Interval tmp;
        if(index1 < list1.size() && index2 < list2.size())
        {
            if(list1[index1].start < list2[index2].start)
            {
                tmp = list1[index1++];
            }
            else
            {
                tmp = list2[index2++];
            }
        }
        else if(index1 == list1.size())
        {
            tmp = list2[index2++];
        }
        else
        {
            tmp = list1[index1++];
        }

        Interval &last = res[res.size() - 1];
        if(res.empty() || tmp.start > last.end)
        {
            res.push_back(tmp);
        }
        else
        {
            last.end = std::max(last.end, tmp.end);
        }

        helper(res, list1, index1, list2, index2);
    }
#endif
};
