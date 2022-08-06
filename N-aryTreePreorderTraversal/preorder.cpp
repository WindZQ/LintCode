#include <vector>
#include <stack>

#define method1 1
#define method2 0

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
    std::vector<int> preorder(UndirectedGraphNode *root)
    {
        std::vector<int> res;
        helper(root, res);
        return res;
    }

    void helper(UndirectedGraphNode *node, std::vector<int> &res)
    {
        if (!node) return;

        res.push_back(node->label);
        for (UndirectedGraphNode *child : node->neighbors)
        {
            helper(child, res);
        }
    }
#endif

#if method2
    std::vector<int> preorder(UndirectedGraphNode *root)
    {
        if (!root) return {};

        std::vector<int> res;
        std::stack<UndirectedGraphNode *> st {{root}};

        while (!st.empty())
        {
            UndirectedGraphNode *t = st.top();
            st.pop();
            res.push_back(t->label);

            for (int i = t->neighbors.size() - 1; i >= 0; --i)
            {
                st.push(t->neighbors[i]);
            }
        }

        return res;
    }
#endif
};
