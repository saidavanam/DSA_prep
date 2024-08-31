// Optimal solution where solution can be obtained in one pass

class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        Node *zerohead = new Node(-1);
        Node *onehead = new Node(-1);
        Node *twohead = new Node(-1);
        
        Node *zero = zerohead,*one = onehead,*two = twohead;
        
        while(head!=nullptr)
        {
            if(head->data==0)
            {
                zero->next = head;
                zero = zero->next;
            }
            else if(head->data==1)
            {
                one->next = head;
                one = one->next;
            }
            else
            {
                two->next = head;
                two = two->next;
            }
            
            head = head->next;
        }
        
        
        
        zero->next = onehead->next?onehead->next:twohead->next; //***
        one->next = twohead->next;
        two->next = nullptr; //***
        
        return zerohead->next;
        
        
        
    }
};
