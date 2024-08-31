
// problem :- https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

/*
    reverse the ll and one to first node and pass the carry. if carry is left out after traversing whole the LL then create new node and insert one to it.
*/


class Solution
{
    public:
    
        // Your Code here
        
      Node* reverse(Node *head)
     {
        Node *temp1=nullptr,*temp2=nullptr;
        
        while(head != nullptr)
        {
            temp1 = head->next;
            head->next = temp2;
            temp2 = head;
            head = temp1;
        }
        
        return temp2;
      }

        
      Node* addOne(Node *head) 
      {
        Node * newhead = reverse(head);
        Node *last = nullptr;
        
        int carry = 1;
        
        Node *ptr = newhead;
        
        while(ptr != nullptr)
        {
           ptr->data = ptr->data + carry;
        //   cout<<ptr->data<<'\n';
           
           if(ptr->data>9)
           {
               ptr->data = 0;
               carry = 1;
           }
           else
           {
               carry = 0;
               break;
           }
           if(ptr->next==nullptr)
           {
               last = ptr;
           }
           ptr = ptr->next;
            
        }
        
        if(carry==1)
        {
            last->next = new Node(1);
        }
        
        Node *newhead2 = reverse(newhead);
        
        
        
        // return head of list after adding one
        return newhead2;
    }
};