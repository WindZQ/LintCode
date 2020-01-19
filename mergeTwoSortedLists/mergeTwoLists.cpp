#include <iostream>
#include <algorithm>

#define method1 1
#define method2 0
#define method3 0
#define method4 0


class Solution
{
public:
#if method1
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return dummy->next;
    }
#endif

#if method2
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
#endif

#if method3
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode *head = l1->val < l2->val ? l1 : l2;
        ListNode *nonhead = l1->val < l2->val ? l2 : l1;
        head->next = mergeTwoLists(head->next, nonhead);
        return head;
    }
#endif

#if method4
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if(!l1 || (l2 && l1->val > l2->val)) std::swap(l1, l2);
        if(l1) l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
#endif
};
