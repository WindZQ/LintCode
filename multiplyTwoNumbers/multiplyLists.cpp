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
    long long mutiplyLists(ListNode *l1, ListNode *l2)
    {
        ListNode *p = l1;
        long long num1 = 0;
        while(p != NULL)
        {
            num1 *= 10;
            num1 += p->val;
            p = p->next;
        }

        p = l2;
        long long num2 = 0;
        while(p != NULL)
        {
            num2 *= 10;
            num2 += p->val;
            p = p->next;
        }

        return num1 * num2;
    }
};
