#include <vector>

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
    TreeNode *constructMaximumBinaryTree(std::vector<int> &nums)
    {
        if(nums.empty()) return NULL;
        int mx = INT_MIN, mx_idx = 0;

        for(int i = 0; i < nums.size(); ++i)
        {
            if(mx < nums[i])
            {
                mx = nums[i];
                mx_idx = i;
            }
        }

        TreeNode *node = new TreeNode(mx);
        std::vector<int> left_arr = std::vector<int>(nums.begin(), nums.begin() + mx_idx);
        std::vector<int> right_arr = std::vector<int>(nums.begin() + mx_idx + 1, nums.end());
        node->left = constructMaximumBinaryTree(left_arr);
        node->right = constructMaximumBinaryTree(right_arr);

        return node;
    }
#endif

#if method2
    TreeNode *constructMaximumBinaryTree(std::vector<int> &nums)
    {
        if(nums.empty()) return NULL;
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode *helper(std::vector<int> &nums, int left, int right)
    {
        if(left > right) return NULL;
        int mid = left;

        for(int i = left + 1; i <= right; ++i)
        {
            if(nums[i] > nums[mid])
            {
                mid = i;
            }
        }

        TreeNode *node = new TreeNode(nums[mid]);
        node->left = helper(nums, left, mid - 1);
        node->right = helper(nums, mid + 1, right);

        return node;
    }
#endif

#if method3
    TreeNode *constructMaximumBinaryTree(std::vector<int> &nums)
    {
        std::vector<TreeNode *> v;

        for(num : nums)
        {
            TreeNode *cur = new TreeNode(num);
            while(!v.empty() && v.back()->val < num)
            {
                cur->left = v.back();
                v.pop_back();
            }

            if(!v.empty())
            {
                v.back()->right = cur;
            }
            v.push_back(cur);
        }

        return v.front();
    }
#endif
};
