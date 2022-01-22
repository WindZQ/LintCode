#include <stack>
#include <queue>

#define method1 1
#define method2 0
#define method3 0
#define method4 0

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
    int sumOfLeftLeaves(TreeNode *root)
    {
        if(!root || !root->left && !root->right) return 0;
        int res = 0;
        helper(root->left, true, res);
        helper(root->right, false, res);
        return res;
    }

    void helper(TreeNode *node, bool left, int &res)
    {
        if(!node) return;
        if(!node->left && node->right && left) res += node->val;
        helper(node->left, true, res);
        helper(node->right, false, res);
    }
#endif

#if method2
    int sumOfLeftLeaves(TreeNode *root)
    {
        if(!root) return 0;
        if(root->left && !root->left->left && !root->left->right)
        {
            return root->left->val + sumOfLeftLeaves(root->right);
        }

        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
#endif

#if method3
    int sumOfLeftLeaves(TreeNode *root)
    {
        if(!root || (!root->left && !root->right)) return 0;
        int res = 0;
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *t = q.front();
            q.pop();
            if(t->left && !t->left->left && !t->left->right) res += t->left->val;
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }

        return res;
    }
#endif

#if method4
    int sumOfLeftLeaves(TreeNode *root)
    {
        if(!root || (!root->left && !root->right)) return 0;
        int res = 0;
        std::stack<TreeNode *> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode *t = s.top();
            s.pop();
            if(t->left && !t->left->left && t->left->right) res += t->left->val;
            if(t->left) s.push(t->left);
            if(t->right) s.push(t->right);
        }

        return res;
    }
#endif
};
