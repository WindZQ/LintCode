#include <stack>
#include <queue>

#define method1 1
#define method2 0
#define method3 0
#define method4 0
#define method5 0

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
    bool isIdentical(TreeNode *a, TreeNode *b)
    {
        if(!a && !b) return true;
        if((a && !b) || (!a && b) || (a->val != b->val)) return false;
        return isIdentical(a->left, b->left) && isIdentical(a->right, b->right);
    }
#endif

#if method2
    bool isIdentical(TreeNode *a, TreeNode *b)
    {
        std::stack<TreeNode*> s;
        s.push(a), s.push(b);
        while(!s.empty())
        {
            a = s.top(); s.pop();
            b = s.top(); s.pop();
            if(!a && !b) continue;
            if((a && !b) || (!a && b) || (a->val != b->val)) return false;
            s.push(a->right); s.push(b->right);
            s.push(a->left); s.push(b->left);
        }
        return true;
    }
#endif

#if method3
    bool isIdentical(TreeNode *a, TreeNode *b)
    {
        std::stack<TreeNode *> s;
        while(a || b || !s.empty())
        {
            while(a || b)
            {
                if((a && !b) || (!a && b) || (a->val != b->val)) return false;
                s.push(a); s.push(b);
                a = a->left; b = b->left;
            }
            a = s.top(); s.pop();
            b = s.top(); s.pop();
            a = a->right; b = b->right;
        }
        return true;
    }
#endif

#if method4
    bool isIdentical(TreeNode *a, TreeNode *b)
    {
        std::stack<TreeNode*> s1, s2;
        TreeNode *head1, *head2;
        while(a || b || !s1.empty() || !s2.empty())
        {
            while(a || b)
            {
                if((a && !b) || (!a && b) || (a->val != b->val)) return false;
                s1.push(a); s2.push(b);
                a = a->left; b = b->left;
            }
            a = s1.top(); b = s2.top();
            if((!a->right || a->right == head1) && (!b->right || b->right == head2))
            {
                s1.pop(); s2.pop();
                head1 = a, head2 = b;
                a = nullptr; b = nullptr;
            }
            else
            {
                a = a->right;
                b = b->right;
            }
        }
        return true;
    }
#endif

#if method5
    bool isIdentical(TreeNode *a, TreeNode *b)
    {
        std::queue<TreeNode *> q;
		q.push(a); q.push(b);
        while(!q.empty())
        {
            a = q.front(); q.pop();
            b = q.front(); q.pop();
            if(!a && !b) continue;
            if((a && !b) || (!a && b) || (a->val != b->val)) return false;
            q.push(a->right); q.push(b->right);
            q.push(a->left); q.push(b->left);
        }
        return true;
    }
#endif
};
