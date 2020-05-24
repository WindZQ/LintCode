#include <iostream>

#define mehtod1 1
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
	ListNode *swapPairs(ListNode *head)
	{
		ListNode *dummy = new ListNode(-1), *pre = dummy;
		dummy->next = head;
		
		while(pre->next && pre->next->next)
		{
			ListNode *t = pre->next->next;
			pre->next->next = t->next;
			t->next = pre->next;
			pre->next = t;
			pre = t->next;
		}
		return dummy->next;
	}
#endif

#if mehtod2
	ListNode *swapPairs(ListNode *head)
	{
		if(!head || !head->next) return head;
		ListNode *t = head->next;
		head->next = swapPairs(head->next->next);
		t->next = head;
		return t;
	}
#endif
};