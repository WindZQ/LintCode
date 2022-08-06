#include <vector>
#include <stack>

#define method1 1
#define method2 0
#define method3 0

struct UndirectedGraphNode
{
    int label;
    std::vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution
{
public:
#if method1
    std::vector<int> postorder(UndirectedGraphNode *root)
    {
        std::vector<int> res;
        helper(root, res);
        return res;
    }

    void helper(UndirectedGraphNode *node, std::vector<int> &res)
    {
        if (!node) return;

        for (UndirectedGraphNode *child : node->neighbors)
        {
            helper(child, res);
        }

        res.push_back(node->label);
    }
#endif

#if method2
    std::vector<int> postorder(UndirectedGraphNode *root)
    {
        if (!root) return {};

        std::vector<int> res;
        std::stack<UndirectedGraphNode*> st{{root}};

        while (!st.empty())
        {
            UndirectedGraphNode *t = st.top();
            st.pop();
            res.insert(res.begin(), t->label);
            for (UndirectedGraphNode *child : t->neighbors)
            {
                if (child) st.push(child);
            }
        }

        return res;
    }
#endif
};
