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
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if(!s) return false;
        if(is_same(s, t)) return true;

        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }

    bool is_same(TreeNode *s, TreeNode *t)
    {
        if(!s && !t) return true;
        if(!s || !t) return false;
        if(s->val != t->val) return false;

        return is_same(s->left, t->left) && is_same(s->right, t->right);
    }
#endif

#if method2
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        std::ostringstream os1, os2;
        serialize(s, os1);
        serialize(t, os2);
        return os1.str().find(os2.str()) != std::string::npos;
    }

    void serialize(TreeNode *node, std::ostringstream &os)
    {
        if(!node)
        {
            os << ",#";
        }
        else
        {
            os << "," << node->val;
            serialize(node->left, os);
            serialize(node->right, os);
        }
    }
#endif
};
