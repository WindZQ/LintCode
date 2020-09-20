#include <queue>
#include <vector>

#define method1 1
#define method2 0
#define method3 0

class MovingAverage
{
public:
#if method1
    std::queue<int> q;
    int size;
    double sum;

    MovingAverage(int size)
    {
        this->size = size;
        sum = 0;
    }

    double next(int val)
    {
        if(q.size() >= size)
        {
            sum -= q.front();
            q.pop();
        }
        q.push(val);
        sum += val;
        return sum / q.size();
    }
#endif

#if method2
    std::vector<double> sum;
    int id;
    int size;

    MovingAverage(int size) : sum(size + 1, 0)
    {
        id = 0;
        this->size = size;
    }

    int mod(int x)
    {
        return x % (size + 1);
    }

    double next(int val)
    {
        id++;
        sum[mod(id)] = sum[mod(id - 1)] + val;
        if(id - size >= 0)
        {
            return (sum[mod(id)] - sum[mod(id - size)]) / size;
        }
        else
        {
            return sum[mod(id)] / id;
        }
    }
#endif

#if method3
    std::vector<double> sum;
    int id;
    int size;

    MovingAverage(int size) : sum(1000000, 0)
    {
        id = 0;
        this->size = size;
    }

    double next(int val)
    {
        id++;
        sum[id] = sum[id - 1] + val;
        if(id - size >= 0)
        {
            return (sum[id] - sum[id - size]) / size;
        }
        else
        {
            return sum[id] / id;
        }
    }
#endif
};
