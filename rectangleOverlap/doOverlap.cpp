#define method1 1
#define method2 0

struct Point
{
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution
{
public:
#if method1
    bool doOverlap(Point &l1, Point &r1, Point &l2, Point &r2)
    {
        if(r1.x < l2.x || l1.x > r2.x || r1.y > l2.y || l1.y <r2.y)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
#endif

#if method2
    bool doOverlap(Point &l1, Point &r1, Point &l2, Point &r2)
    {
        if(l2.x > r1.x || l1.x > r2.x)
        {
            return false;
        }

        if(r2.y > l1.y || r1.y > l2.y)
        {
            return false;
        }

        return true;
    }
#endif
}
