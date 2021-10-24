#include <pair>
#include <queue>
#include <unordered_map>
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
#if method1
    int diameterOfBinaryTree(TreeNode *root)
    {
        std::pair<int, int> result = helper(root);
        return result.second;
    }

    std::pair<int, int> helper(TreeNode *root)
    {
        if(root == nullptr) return make_pair(0, 0);

        std::pair<int, int> left_result = helper(root->left);
        std::pair<int, int> right_result = helper(root->right);

        int longest = std::max(left_result.first, right_result.first) + 1;
        int diameter = std::max({left_result.second, right_result.second, left_result.first + right_result.first});

        return make_pair(longest, diameter);
    }
#endif

#if method2
    int diameterOfBinaryTree(TreeNode *root)
    {
        std::unordered_map<TreeNode *, int> longest;
        std::unordered_map<TreeNode *, int> diameter;
        std::queue<TreeNode *> node_queue;

        node_queue.push(root);
        std::vector<TreeNode *> bfs_order;

        while(!node_queue.empty())
        {
            TreeNode *node = node_queue.front();
            node_queue.pop();

            if(node == nullptr) continue;

            bfs_order.push_back(node);
            node_queue.push(node->left);
            node_queue.push(node->right);
        }

        longest[nullptr] = 0;
        diameter[nullptr] = 0;

        std::reverse(bfs_order.begin(), bfs_order.end());

        for(TreeNode *node : bfs_order)
        {
            int left_longest = longest[node->left];
            int right_longest = longest[node->right];
            int left_diameter = diameter[node->left];
            int right_diameter = diameter[node->right];

            longest[node] = std::max(left_longest, right_longest) + 1;
            diameter[node] = std::max({left_diameter, right_diameter, left_longest + right_longest});
        }

        return diameter[root];
    }
#endif
};
