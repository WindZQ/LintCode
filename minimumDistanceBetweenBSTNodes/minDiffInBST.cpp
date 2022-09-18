#include <stack>
#include <vector>

#define method1 1
#define method2 0
#define method3 0
#define method4 0

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val)
    {
        this->val = val;
        this->left = this->right = NULL;
    }
}

class Solution
{
public:
#if method1
    int minDiffInBST(TreeNode *root)
    {
        int res = INT_MAX;
        std::vector<int> v;
        helper(root, v);

        for (int i = 1; i < v.size(); ++i)
        {
            res = std::min(res, v[i] - v[i -1]);
        }

        return res;
    }

    void helper(TreeNode *node, std::vector<int> &values)
    {
        if (!node) return;
        helper(node->left, values);
        values.push_back(node->val);
        helper(node->right, values);
    }
#endif

#if method2
    int minDiffInBST(TreeNode *root)
    {
        int res = INT_MAX, pre = -1;
        helper(root, pre, res);
        return res;
    }

    void helper(TreeNode *node, int &pre, int &res)
    {
        if (!node) return;
        helper(node->left, pre, res);
        if (pre != -1) res = std::min(res, node->val - pre);
        pre = node->val;
        helper(node->right, pre, res);
    }
#endif

#if method3
    int minDiffInBST(TreeNode *root)
    {
        int res = INT_MAX;
        helper(root, INT_MIN, INT_MAX, res);
        return res;
    }

    void helper(TreeNode *node, int low, int high, int &res)
    {
        if (!node) return;
        if (low != INT_MIN) res = std::min(res, node->val - low);
        if (high != INT_MAX) res = std::min(res, high - node->val);
        helper(node->left, low, node->val, res);
        helper(node->right, node->val, high, res);
    }
#endif

#if method4
    int minDiffInBST(TreeNode *root)
    {
        int res = INT_MAX, pre = -1;
        std::stack<TreeNode*> st;
        TreeNode *p = root;

        while (!st.empty() || p)
        {
            if (p)
            {
                st.push(p);
                p = p->left;
            }
            else
            {
                p = st.top();
                st.pop();
                if (pre != -1) res = std::min(res, p->val - pre);
                pre = p->val;
                p = p->right;
            }
        }

        return res;
    }
#endif
};
