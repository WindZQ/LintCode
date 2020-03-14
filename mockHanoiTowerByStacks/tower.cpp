#include <iostream>
#include <stack>


class Tower
{
private:
    stack<int> disks;
public:

    Tower(int i)
    {

    }

    void add(int d)
    {
        if (!disks.empty() && disks.top() <= d)
        {
            printf("Error placing disk %d", d);
        }
        else
        {
            disks.push(d);
        }
    }

    void moveTopTo(Tower &t)
    {
        t.add(disks.top());
        disks.pop();
    }

    void moveDisks(int n, Tower &destination, Tower &buffer)     {
        if(n > 0)
        {
            moveDisks(n - 1, buffer, destination);
            moveTopTo(destination);
            buffer.moveDisks(n - 1, destination, *this);
        }
    }

    stack<int> getDisks()
    {
        return disks;
    }
};
