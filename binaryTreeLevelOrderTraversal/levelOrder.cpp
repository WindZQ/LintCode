#include <iostream>
#include <vector>

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
    //
#if method1
    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        if(!root)
            return {};
        std::vector<std::vector<int>> res;
        std::queue<TreeNode*> q {{root}};
        while(!q.empty())
        {
            std::vector<int> oneLevel;
            for(int i = q.size(); i > 0; --i)
            {
                TreeNode *t = q.front();
                q.pop();
                oneLevel.push_back(t->val);
                if(t->left)  q.push(t->left);
                if(t->right) q.push(t->right);
            }
            res.push_back(oneLevel);
        }
        return res;
    }
#endif

    //
#if method2
    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        std::vector<std::vector<int>> res;
        levelOrder(root, 0 ,res);
        return res;
    }

    void levelOrder(TreeNode *node, int level, std::vector<std::vector<int>> &res)
    {
        if(!node) return;
        if(res.size() == level) res.push_back({});
        res[level].push_back(node->val);
        if(node->left) levelOrder(node->left, level + 1, res);
        if(node->right) levelOrder(node->right, level + 1, res);
    }
#endif
};

int main()
{
    std::vector<std::vector<int>> res;
    TreeNode *root;
    Solution s;
    res = s.levelOrder(root);
    return 0;
}
