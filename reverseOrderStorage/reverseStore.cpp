#include <vector>

#define method1 1
#define method2 0

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class Solution
{
public:
#if method1
    std::vector<int> reverseStore(ListNode *head)
    {
        std::vector<int> res;
        helper(head, res);
        return res;
    }

    void helper(ListNode *head, std::vector<int> &res)
    {
        if(head == NULL)
        {
            return;
        }
        else
        {
            helper(head->next, res);
        }

        res.push_back(head->val);
    }
#endif

#if method2
    std::vector<int> reverseStore(ListNode *head)
    {
        std::vector<int> res;
        if(head == NULL) return res;

        ListNode *p = head;
        while(p != NULL)
        {
            res.push_back(p->val);
            p = p->next;
        }

        std::reverse(res.begin(), res.end());
        return res;
    }
#endif
};
