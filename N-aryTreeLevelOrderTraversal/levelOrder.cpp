#include <vector>
#include <queue>

#define method1 1
#define method2 0

struct UndirectedGraphNode
{
    int label;
    std::vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Soltion
{
public:
#if method1
    std::vector<std::vector<int>> levelOrder(UndirectedGraphNode *root)
    {
        std::vector<std::vector<int>> res;
        helper(root, 0, res);
        return res;
    }

    void helper(UndirectedGraphNode *node, int level, std::vector<std::vector<int>> &res)
    {
        if (!node) return;

        if (res.size() <= level)
        {
            res.resize(res.size() + 1);
        }
        res[level].push_back(node->label);

        for (auto a : node->neighbors)
        {
            helper(a, level + 1, res);
        }
    }
#endif

#if method2
    std::vector<std::vector<int>> levelOrder(UndirectedGraphNode *root)
    {
        if (!root) return {};

        std::vector<std::vector<int>> res;
        std::queue<UndirectedGraphNode*> q{{root}};

        while (!q.empty())
        {
            std::vector<int> out;

            for (int i = q.size(); i > 0; --i)
            {
                auto t = q.front();
                q.pop();
                out.push_back(t->label);

                if (!t->neighbors.empty())
                {
                    for (auto a : t->neighbors)
                    {
                        q.push(a);
                    }
                }
            }

            res.push_back(out);
        }

        return res;
    }
#endif
};
