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
    TreeNode * mergeTrees(TreeNode *t1, TreeNode *t2)
    {
        TreeNode *res = NULL;
        helper(t1, t2, res);
        return res;
    }

    void helper(TreeNode *t1, TreeNode *t2, TreeNode* &res)
    {
        if(!t1 && !t2) return;
        else if(t1 && !t2)
        {
            res = new TreeNode(t1->val);
            helper(t1->left, NULL, res->left);
            helper(t1->right, NULL, res->right);
        }
        else if(!t1 && t2)
        {
            res = new TreeNode(t2->val);
            helper(NULL, t2->left, res->left);
            helper(NULL, t2->right, res->right);
        }
        else
        {
            res = new TreeNode(t1->val + t2->val);
            helper(t1->left, t2->left, res->left);
            helper(t1->right, t2->right, res->right);
        }
    }
#endif

#if method2
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
    {
        if(!t1) return t2;
        if(!t2) return t1;

        TreeNode *t = new TreeNode(t1->val + t2->val);
        t->left = mergeTrees(t1->left, t2->left);
        t->right = mergeTrees(t1->right, t2->right);

        return t;
    }
#endif
};
