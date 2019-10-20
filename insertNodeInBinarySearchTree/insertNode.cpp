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
    //时间复杂度为O(logn),空间复杂度为O(1)
#if method1
    TreeNode * insertNode(TreeNode *root, TreeNode *node)
    {
        if(NULL == root)
            return node;
        if(node->val < root->val)
        {
            root->left = insertNode(root->left, node);
            return root;
        }
        else
        {
            root->right = insertNode(root->right, node);
            return root;
        }
    }
#endif

    //时间复杂度为O(n),空间复杂度为O(1)
#if method2
    TreeNode * insertNode(TreeNode *root, TreeNode *node)
    {
        if(NULL == root)
            return node;
        TreeNode *cur = root;
        TreeNode *prev = NULL;
        while(cur != NULL)
        {
            prev = cur;
            cur = cur->val > node->val ? cur->left : cur->right;
        }
        if(prev->val > node->val)
            prev->left = node;
        else
            prev->right = node;
        return root;
    }
#endif
};
