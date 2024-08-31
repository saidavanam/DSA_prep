class LinkedList
{

public:
    class Node
    {
     public:
        int val;
        Node*next;

        Node(int data)
        {
            val = data;
            next = nullptr;

        }
    };
    Node *insert_at_start(Node*head,int data)
    {
        Node *node = new Node(data);
        if(head==nullptr)
        {
            head = node;
        }
        else
        {
            node->next = head;
            head = node;
        }

        return head;
    }

    Node *insert_at_last(Node*head,int data)
    {
        Node *node = new Node(data);

        if(head==nullptr)
        {
            head = node;
        }
        else
        {
            temp = head;
            while(temp->next!=nullptr)
            {
                temp = temp->next;
            }
            temp->next = node;
        }

        return head;
    }

    Node *findmiddle(Node*head)
    {
        if(head==nullptr)
        {
            return nullptr;
        }

        Node *slow = head;
        Node * fast = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

};