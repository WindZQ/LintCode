#include <algorithm>

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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if(!root) return NULL;
        if(root->val > std::max(p->val, q->val))
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if(root->val < std::min(p->val, q->val))
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        else
        {
            return root;
        }
    }
#endif

#if method2
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        while(true)
        {
            if(root->val > std::max(p->val, q->val))
            {
                root = root->left;
            }
            else if(root->val < std::min(p->val, q->val))
            {
                root = root->right;
            }
            else
            {
                break;
            }
        }

        return root;
    }
#endif
};
