#include <iostream>

#define method1 1
#define method2 0


class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val)
    {
        this->val  = val;
        this->next = NULL;
    }
};

class Solution
{
public:
#if method1
    ListNode *addList(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(0);
        ListNode *ptr = head;
        int carry = 0;
        while(true)
        {
            if(l1 != NULL)
            {
                carry += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL)
            {
                carry += l2->val;
                l2 = l2->next;
            }
            ptr->val = carry % 10;
            carry /= 10;

            if(l1 != NULL || l2 != NULL || carry != 0)
            {
                ptr = (ptr->next = new ListNode(0));
            }
            else
            {
                break;
            }
        }
        return head;
    }
#endif

#if method2
    ListNode *addList(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        int carry = 0;
        while(l1 || l2)
        {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int sum = val1+ val2 + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(carry) cur->next = new ListNode(1);
        return dummy->next;
    }
#endif
};
