#include <math>

#defind method1 1
#defind method2 0
#defind method3 0

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
    int closestValue(TreeNode *root, double target)
    {
        int closest = root->val;

        while(root)
        {
            if(std::abs(closest - target) >= std::abs(root->val - target))
            {
                closest = root->val;
            }

            root = target < root->val ? root->left : root->right;
        }

        return closest;
    }
#endif

#if method2
    int closestValue(TreeNode *root, double target)
    {
        if(root == NULL) return -1;

        TreeNode *less_node = root;
        TreeNode *bigger_node = root;
        TreeNode *curt = root;

        while(curt != NULL)
        {
            if(curt->val == target)
            {
                return target;
            }
            else if(curt->val > target)
            {
                bigger_node = curt;
                curt = curt->left;
            }
            else
            {
                less_node = curt;
                curt = curt->right;
            }
        }

        if(std::abs(less_node->val - target) < std::abs(bigger_node->val - target))
        {
            return less_node->val;
        }

        return bigger_node->val;
    }
#endif

#if method3
    int closestValue(TreeNode *root, double target)
    {
        TreeNode *min = nullptr;
        double min_diff = std::numeric_limits<double>::max();

        while(root != nullptr)
        {
            double diff = std::abs(root->val - target);
            if(diff < min_diff)
            {
                min_diff = diff;
                min = root;
            }

            if(root->val == target) break;
            if(target < root->val)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }

        return (min == nullptr) ? 0 : min->val;
    }
#endif
};
