#include <iostream>

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
    TreeNode *cloneTree(TreeNode *root)
    {
        if(root == NULL) return NULL;

        TreeNode *clone_root = new TreeNode(root->val);
        clone_root->left = cloneTree(root->left);
        clone_root->right = cloneTree(root->right);

        return clone_root;
    }
};
