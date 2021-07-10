#include <vector>
#include <queue>
#include <unordered_map>

#define method1 1
#define method2 0

class Employee
{
public:
    int id;
    int importance;
    std::vector<int> subordinates;
};

class Solution
{
public:
#if method1
    int getImportance(std::vector<Employee *> employees, int id)
    {
        std::unordered_map<int, Employee*> m;
        for(auto e : employees) m[e->id] = e;
        return helper(id, m);
    }

    int helper(int id, std::unordered_map<int, Employee *> &m)
    {
        int res = m[id]->importance;

        for(int num : m[id]->subordinates)
        {
            res += helper(num, m);
        }

        return res;
    }
#endif

#if method2
    int getImportance(std::vector<Employee * > employees, int id)
    {
        int res = 0;
        std::queue<int> q{{id}};
        std::unordered_map<int, Employee*> m;
        for(auto e : employees) m[e->id] = e;

        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            res += m[t]->importance;

            for(int num : m[t]->subordinates)
            {
                q.push(num);
            }
        }

        return res;
    }
#endif
};
