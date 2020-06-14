#include <unordered_set>

#define method1 1
#define method2 0

class ParentTreeNode
{
public:
    int val;
    ParentTreeNode *parent, *left, *right;
};


class Solution
{
public:
#if method1
    ParentTreeNode *lowestCommonAncestorII(ParentTreeNode *root, ParentTreeNode *A, ParentTreeNode *B)
    {
        if(root == NULL || root == A || root == B) return root;
        ParentTreeNode *left = lowestCommonAncestorII(root->left, A, B);
        ParentTreeNode *right = lowestCommonAncestorII(root->right, A, B);

        if(left && right)
        {
            return root;
        }
        else
        {
            return left == NULL ? right : left;
        }
    }
#endif

#if method2
    ParentTreeNode *lowestCommonAncestorII(ParentTreeNode *root, ParentTreeNode *A, ParentTreeNode *B)
    {
        if(root == NULL) return root;
        if(A == NULL) return B;
        if(B == NULL) return A;

        std::unordered_set<ParentTreeNode*> hashA;
        std::unordered_set<ParentTreeNode*> hashB;
        hashA.insert(A);
        hashB.insert(B);

        while(A != root && B != root)
        {
            A = A->parent;
            B = B->parent;

            if(A == B)
            {
                return A;
            }
            if(hashA.find(B) != hashA.end())
            {
                return B;
            }
            if(hashB.find(A) != hashB.end())
            {
                return A;
            }

            hashA.insert(A);
            hashB.insert(B);
        }

        while(B != root)
        {
            B = B->parent;
            if(hashA.find(B) != hashA.end())
            {
                return B;
            }
            hashB.insert(B);
        }

        while(A != root)
        {
            A = A->parent;
            if(hashB.find(A) != hashB.end())
            {
                return A;
            }
            hashA.insert(A);
        }

        return root;
    }
#endif
};
