#include <queue>

#define method1 1
#define method2 0


class MyStack
{
public:
#if method1
    std::queue<int> q1;
    std::queue<int> q2;

    MyStack()
    {

    }

    void push(int x)
    {
        q2.push(x);

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        std::swap(q1, q2);
    }

    int pop()
    {
        int r = q1.front();
        q1.pop();

        return r;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
#endif

#if method2
    std::queue<int> q;

    MyStack()
    {

    }

    void push(int x)
    {
        int n = q.size();
        q.push(x);

        for (int i = 0; i < n; ++i)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int r = q.front();
        q.pop();

        return r;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
#endif
};
