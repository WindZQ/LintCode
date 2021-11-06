#include <stack>
#include <algorithm>

#define method1 1
#define method2 0
#define method3 0

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
};

class Solution
{
public:
#if method1
    int getMinimumDifference(TreeNode *root)
    {
        int res = INT_MAX, pre = -1;
        inorder(root, pre, res);
        return res;
    }

    void inorder(TreeNode *root, int &pre, int &res)
    {
        if(!root) return;
        inorder(root->left, pre, res);
        if(pre != -1) res = std::min(res, root->val - pre);
        pre = root->val;
        inorder(root->right, pre, res);
    }
#endif

#if method2
    int getMinimumDifference(TreeNode *root)
    {
        int res = INT_MAX;
        helper(root, INT_MIN, INT_MAX, res);
        return res;
    }

    void helper(TreeNode *root, int low, int high, int &res)
    {
        if(!root) return;
        if(low != INT_MIN) res = std::min(res, root->val - low);
        if(high != INT_MAX) res = std::min(res, high - root->val);
        helper(root->left, low, root->val, res);
        helper(root->right, root->val, high, res);
    }
#endif

#if method3
    int getMinimumDifference(TreeNode *root)
    {
        int res = INT_MAX, pre = -1;
        std::stack<TreeNode *> st;
        TreeNode *p = root;

        while(p || !st.empty())
        {
            while(p)
            {
                st.push(p);
                p = p->left;
            }

            p = st.top();
            st.pop();
            if(pre != -1) res = std::min(res, p->val - pre);
            pre = p->val;
            p = p->right;
        }

        return res;
    }
#endif
};
