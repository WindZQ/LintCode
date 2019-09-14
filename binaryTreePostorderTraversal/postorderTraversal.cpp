#include <iostream>
#include <vector>
#include <stack>

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
    //构造二叉树
    void CreatBiTree(TreeNode * T)
    {
        for(int i = 0; i < 3; ++i)
        {
            TreeNode *T = new TreeNode();
            T->val = i;
            CreatBiTree(T->left);
            CreatBiTree(T->right);
        }
    }

    //输出
    void print(std::vector<int> result)
    {
         for(int i = 0; i < result.size(); ++i)
             std::cout << result[i] << "\t";
         std::cout << std::endl;
    }
    //
#define method1
    std::vector<int> res;
    void traversal(TreeNode *root)
    {
        if(NULL == root)
            return;
        traversal(root->left);
        traversal(root->right);
        res.push_back(root->val);
    }
    std::vector<int> postorderTraversal(TreeNode *root)
    {
        res.clear();
        traversal(root);
        return res;
    }
#endif

    //
#define method2
    std::vector<int> postorderTraversal(TreeNode *root)
    {
        if(!root)
            return {};
        std::vector<int> res;
        std::stack<TreeNode *> s{{root}};
        TreeNode *head = root;
        while(!s.empty())
        {
            TreeNode *t = s.top();
            if((!t->left && !t->right) || t->left == head || t->right == head)
            {
                res.push_back(t->val);
                s.pop();
                head = t;
            }
            else
            {
                if(t->right) s.push(t->right);
                if(t->left)  s.push(t->left);
            }
        }
        return res;
    }
#endif

    //
#define method3
    std::vector<int> postorderTraversal(TreeNode *root)
    {
        if(!root)
            return {};
        std::vector<int> res;
        std::stack<TreeNode *>s {{root}};
        while(!s.empty())
        {
            TreeNode *t = s.top();
            s.pop();
            res.insert(res.begin(), t->val);
            if(t->left)  s.push(t->left);
            if(t->right) s.push(t->right);
        }
        return res;
    }
#endif

    //
#define method4
    std::vector<int> postorderTraversal(TreeNode *root)
    {
        std::vector<int> res;
        std::stack<TreeNode* > s;
        TreeNode *p = root;
        while(!s.empty() || p)
        {
            if(p)
            {
                s.push(p);
                res.insert(res.begin(), p->val);
                p = p->right;
            }
            else
            {
                TreeNode *t = s.top();
                s.pop();
                p = t->left;
            }
        }
        return res;
    }
#endif

    //
#define method5
    std::vector<int> postorderTraversal(TreeNode *root)
    {
        if(!root)
            return {};
        std::vector<int> res;
        std::stack<TreeNode *> s1, s2;
        s1.push(root);
        while(!s1.empty())
        {
            TreeNode *t = s1.top();
            s1.pop();
            s2.push(t);
            if(t->left)  s1.push(t->left);
            if(t->right) s1.push(t->right);
        }
        while(!s2.empty())
        {
            res.push_back(s2.top()->val);
            s2.pop();
        }
        return res;
    }
#endif
};

int main()
{
    TreeNode *t = NULL;
    std::vector<int> res;
    Solution s;
    s.CreatBiTree(t);
    s.postorderTraversal(t);
    s.print(res);
    return 0;
}
