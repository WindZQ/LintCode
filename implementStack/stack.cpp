class Stack
{
private:
    struct node
    {
        int val;
    public:
        node *pre;
        node *next;
        node(int v): val(v)
        {
            pre = nullptr;
            next = nullptr;
        };
    };

    node *dummy;
    node *current;

public:
    Stack()
    {
        dummy = new node(0);
        current = dummy;
    }

    ~Stack()
    {

    }

    void push(int x)
    {
        node *tmp = new node(x);
        current->next = tmp;
        tmp->pre = current;
        current = tmp;
    }

    void pop()
    {
        if(current != dummy)
        {
            node *tmp = current;
            current = current->pre;
            current->next = nullptr;
            delete tmp;
        }
    }

    int top()
    {
        assert(current != dummy);
        return current->val;
    }

    bool isEmpty()
    {
        if(current != dummy)
        {
            return false;
        }
        return true;
    }
};
