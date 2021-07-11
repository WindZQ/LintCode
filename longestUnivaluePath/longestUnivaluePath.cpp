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
    int longestUnivaluePath(TreeNode *root)
    {
        int res = 0;
        helper(root, res);
        return res;
    }

    int helper(TreeNode *node, int &res)
    {
        if(!node) return 0;
        int left = helper(node->left, res);
        int right = helper(node->right, res);
        left = (node->left && node->val  == node->left->val) ? left + 1 : 0;
        right = (node->right && node->val == node->right->val) ? right + 1 : 0;
        res = std::max(res, left + right);

        return std::max(left, right);
    }
#endif

#if method2
    int longestUnivaluePath(TreeNode *root)
    {
        int res = 0;
        if(root) helper(root, root->val, res);
        return res;
    }

    int helper(TreeNode *node, int parent, int &res)
    {
        if(!node) return 0;
        int left = helper(node->left, node->val, res);
        int right = helper(node->right, node->val, res);
        res = std::max(res, left + right);
        if(node->val == parent) return std::max(left, right) + 1;
        return 0;
    }
#endif

#if method3
    int longestUnivaluePath(TreeNode *root)
    {
        if(!root) return 0;
        int sub = std::max(longestUnivaluePath(root->left), longestUnivaluePath(root->right));
        return std::max(sub, helper(root->left, root->val) + helper(root->right, root->val));
    }

    int helper(TreeNode *node, int parent)
    {
        if(!node || node->val != parent)
            return 0;
        return 1 + std::max(helper(node->left, node->val), helper(node->right, node->val));
    }
#endif
};
