#include <iostream>
#include <vector>
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

class Solution : public TreeNode
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

    //时间复杂度为O(n),空间复杂度为O(1)
#if method1
    std::vector<int> res;
    void traverse(TreeNode *root)
    {
        if(!root)
            return ;
        res.push_back(root->val);
        traverse(root->left);
        traverse(root->right);
    }
    std::vector<int> preorderTraversal(TreeNode *root)
   {
       res.clear();
       traverse(root);
       return res;
   }
#endif

    //时间复杂度为O(1),空间复杂度为O(n)
#if method2
    std::vector<int> preorderTraversal(TreeNode *root)
    {
        if(!root) return {};
        std::vector<int> res;
        std::stack<TreeNode *> s{{root}};
        while(!s.empty())
        {
            TreeNode *t = s.top();
            s.pop();
            res.push_back(t->val);
            if(t->right) s.push(t->right);
            if(t->left)  s.push(t->let);
        }
        return res;
    }
#endif

#if method3
    //时间复杂度为O(1), 空间复杂度为O(n);
    std::vector<int> preorderTraversal(TreeNode *root)
    {
        std::vector<int> res;
        std::stack<TreeNode*> s;
        TreeNode *p = root;
        while(!s.empty() || p)
        {
            if(p)
            {
                s.push(p);
                res.push_back(p->val);
                p = p->left;
            }
            else
            {
                TreeNode *t = s.top();
                s.pop();
                p = t->right;
            }
        }
        return res;
    }
#endif
};

int main()
{
    std::vector<int> res;
    TreeNode *root;
    Solution s;
    s.CreatBiTree(root);
    res = s.preorderTraversal(root);
    s.print(res);
    return 0;
}
