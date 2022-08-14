#include <vector>

#define method1 1
#define method2 0
#define method3 0

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
    ListNode *middleNode(ListNode *head)
    {
        std::vector<ListNode *> m = {head};

        while (m.back()->next != NULL)
        {
            m.push_back(m.back()->next);
        }

        return m[m.size() / 2];
    }
#endif

#if method2
    ListNode *middleNode(ListNode *head)
    {
        int n = 0;
        ListNode *cur = head;

        while (cur != nullptr)
        {
            ++n;
            cur = cur->next;
        }

        int k = 0;
        cur = head;

        while (k < n / 2)
        {
            ++k;
            cur = cur->next;
        }

        return cur;
    }
#endif

#if method3
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
#endif
};
