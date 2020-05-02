#include <stack>

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
    void flatten(TreeNode *root)
    {
        if(!root) return;
        if(root->left) flatten(root->left);
        if(root->right) flatten(root->right);
        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = NULL;
        while(root->right) root = root->right;
        root->right = tmp;
    }
#endif

#if method2
    void flatten(TreeNode *root)
    {
        TreeNode *cur = root;
        while(cur)
        {
            if(cur->left)
            {
                TreeNode *p = cur->left;
                while(p->right) p = p->right;
                p->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
#endif

#if method3
    void flatten(TreeNode *root)
    {
        if(!root) return;
        std::stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode *t = s.top();
            s.pop();
            if(t->left)
            {
                TreeNode *r = t->left;
                while(r->right) r = r->right;
                r->right = t->right;
                t->right = t->left;
                t->left = NULL;
            }
            if(t->right) s.push(t->right);
        }
    }
#endif
};
