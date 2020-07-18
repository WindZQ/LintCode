#define method1 1
#define method2 0

class Node
{
public:
    int val;
    Node *next;
    Node(int _val)
    {
        val = _val, next = NULL;
    }
};

class MyQueue
{
public:
#if method1
    Node * first, *last;

    MyQueue()
    {
        first = last = NULL;
    }

    void enqueue(int item)
    {
        if(!first)
        {
            last = new Node(item);
            first = last;
        }
        else
        {
            last->next = new Node(item);
            last = last->next;
        }
    }

    int dequeue()
    {
        if(first != NULL)
        {
            int item = first->val;
            first = first->next;
            return item;
        }
        return -1;
    }
#endif

#if method2
    Node *dummy, *curr;

    MyQueue()
    {
        dummy = new Node(-1);
        curr = dummy;
    }

    void enqueue(int item)
    {
        Node *temp = new Node(item);
        curr->next = temp;
        curr = temp;
    }

    int dequeue()
    {
        if(dummy->next == NULL)
        {
            return -1;
        }

        if(dummy->next == curr)
        {
            Node *temp = curr;
            dummy->next = NULL;
            curr = dummy;
            return temp->val;
        }
        else
        {
            Node *temp = dummy->next;
            dummy->next = dummy->next->next;
            return temp->val;
        }
    }
#endif
};
