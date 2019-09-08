#include <iostream>
#include <stack>
#include <vector>
#define method1 1
#define method2 0
#define method3 0

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x)
                    , left(NULL)
                    , right(NULL)
    {

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
    //时间复杂度为O(n),空间复杂度为O(1)
#if method1
    std::vector<int> res;
    void traverse(TreeNode *root)
    {
        i(!root)
            return;
        traverse(root->left);
        res.push_back(root->val);
        traverse(root->right);
    }
    std::vector<int> inorderTraversal(TreeNode *root)
    {
        res.clear();
        traverse(root);
        return res;
    }
#endif

    //时间复杂度为O(1),空间复杂度为O(n)
#if method2
    std::vector<int> inorderTraversal(TreeNode *root)
    {
        std::vector<int> res;
        std::stack<TreeNode* > s;
        TreeNode *p = root;
        while(!s.empty() || p)
        {
            while(p)
            {
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            res.push_back(p->val);
            p = p->right;
        }
        return res;
    }
#endif

    //时间复杂度为O(1),空间复杂度为O(n)
#if method3
    std::vector<int> inorderTraversal(TreeNode *root)
    {
        std::vector<int> res;
        TreeNode *p = root;
        std::stack<TreeNode*> s;
        while(!s.empty() || p)
        {
            if(p)
            {
                s.push(p);
                p = p->left;
            }
            else
            {
                p = s.top();
                s.pop();
                res.push_back(p->val);
                p = p->right;
            }
        }
        return res;
    }
#endif
};

int main()
{
    TreeNode root;
    std::vector<int> res;
    Solution s;
    s.creatTree(root);
    res = s.inorderTraversal(root);
    s.print(res);
    return 0;
}
