
/*
Brute force solution :- Using hashing to keep track of nodes.
*/


int countNodesinLoop(struct Node *head)
{
    map<Node*,int> counter;
    int count = 0;
    
    Node*temp = head;
    
    while(temp!=nullptr)
    {
        count++;
        temp = temp->next;
        
        while(counter.find(temp)!=counter.end())
        {
            return count - counter[temp];
        }
        counter[temp] = count;
    }
    
    return 0;
}

/*
 Time complexity O(n*2*logn).
 space complexity O(n).
*/

/*
 Optimal solution:- using slow and pointer method.
 if slow == fast then count nodes in loop
*/

int countNodesinLoop(struct Node *head)
{
    struct Node *slow = head, *fast = head;
    

    // Step 1: Detect the loop using Floyd’s cycle-finding algorithm
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            int count = 1; // counting fast
            fast = fast->next;
            while(slow != fast)
            {
                count++;
                fast = fast->next;
            }
            
            return count;
        }
    }

    return 0;
}

