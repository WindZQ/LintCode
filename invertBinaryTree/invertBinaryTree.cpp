#include <iostream>
#include <queue>

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
    void invertBinaryTree(TreeNode *root)
    {
        dfs(root);
    }
#endif

#if method2
    TreeNode *invertBinaryTree(TreeNode *root)
    {
        if(!root)
        {
            return NULL;
        }
        TreeNode *tmp = root->left;
        root->left = invertBinaryTree(root->right);
        root->right = invertBinaryTree(tmp);
        return root;
    }
#endif

#if method3
    TreeNode *invertBinaryTree(TreeNode *root)
    {
        if(!root)
        {
            return NULL;
        }
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            TreeNode *tmp = node->left;
            node->left = node->right;
            node->right = tmp;
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
        return root;
    }
#endif

private:
    void dfs(TreeNode *node)
    {
        TreeNode *left = node->left, *right = node->right;
        node->left = right;
        node->right = left;
        if(left != NULL)
        {
            dfs(left);
        }
        if(right != NULL)
        {
            dfs(right);
        }
    }
};
