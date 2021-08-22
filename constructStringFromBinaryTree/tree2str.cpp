#include <string>

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
    std::string tree2str(TreeNode *t)
    {
        if(!t) return "";
        std::string res = "";
        helper(t, res);

        return std::string(res.begin() + 1, res.end() - 1);
    }

    void helper(TreeNode *t, std::string &res)
    {
        if(!t) return;

        res += "(" + to_string(t->val);
        if(!t->left && t->right) res += "()";
        helper(t->left, res);
        helper(t->right, res);
        res += ")";
    }
#endif

#if method2
    std::string tree2str(TreeNode *t)
    {
        if(!t) return "";
        std::string res = to_string(t->val);
        std::string left = tree2str(t->left), right = tree2str(t->right);

        if(left == "" && right == "") return res;
        if(left == "") return res + "()" + "(" + right + ")";
        if(right == "") return res + "(" + left + ")";

        return res + "(" + left + ")" + "(" + right + ")";
    }
#endif

#if method3
    std::string tree2str(TreeNode *t)
    {
        if(!t) return "";
        std::string res = to_string(t->val);
        if(!t->left && !t->right) return res;
        res += "(" + tree2str(t->left) + ")";
        if(t->right) res += "(" + tree2str(t->right) + ")";

        return res;
    }
#endif
};
