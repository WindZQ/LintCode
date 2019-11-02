#include <iostream>
#define method1 1
#define method2 0

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
    int depth(TreeNode *root)
    {
        if(NULL == root)
            return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        if(left == -1 || right == -1 || abs(left - right) > 1)
            return -1;
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        return depth(root) != -1;
    }
#endif

#if method2
    int get_depth(TreeNode *root)
    {
        if(!root) return 0;
        return 1 + max(get_depth(root->left), get_depth(root->right));
    }

    bool isBalanced(TreeNode *root)
      {
        if(!root) return true;
        if(abs(get_depth(root->left) - get_depth(root->right)) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
#endif
}
