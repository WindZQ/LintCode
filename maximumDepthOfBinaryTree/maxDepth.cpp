#inclue <iostream>
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
#if method1
public:
    int maxDepth(TreeNode *root)
    {
        if(NULL == root)
            return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return left > right ? left + 1 : right + 1;
    }
#endif

#if method2
    int maxDepth(TreeNode *root)
    {
        if(!root)
            return 0;
        int res = 0;
        queue<TreeNode *> q{{root}};
        while(!q.empty())
        {
            ++res;
            for(int i = q.size(); i > 0; --i)
            {
                TreeNode *t = q.front();
                q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        }
        return res;
    }
#endif

#if method3
    int maxDepth(TreeNode *root)
    {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        int left = 1, right = 1;
        if(root->left) left += maxDepth(root->left);
        if(root->right) right += maxDepth(root->right);
        return left > right ? left : right;
    }
#endif
};
