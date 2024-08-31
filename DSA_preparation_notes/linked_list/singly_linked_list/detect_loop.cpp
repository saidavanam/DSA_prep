
// leetcode problem no.141

/* Better solution using sets. sets are used to record pointers. while traversing if a pointer is found in the set then loop is present in the linked list
or else if we reach null then loop is not present in the linked list*/

bool hasCycle(ListNode *head) {
        
        set<ListNode*> st;

        ListNode *start = head;
        int i=0;
        int action =0;

        if(head==NULL)
        {
            return action;
        }

        while(true && start->next!=NULL)
        {
            if(st.find(start)==st.end())
            {
                st.insert(start);
                start = start->next;
            }
            else
            {
                action = 1;
                break;
            }

        }

        return action;
        
    }

// Time complexity is o(nlogn) and space complexity is o(n)

/* Optimal approach using fast and slow pointer. if fast and slow pointer reach at same pointer then loop is been detected or else fast or fast->next is
null then loop is not present in the linked list */

bool hasCycle(ListNode *head) {
        
        ListNode *slow = head,*fast = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow==fast)
            {
                return true;
            }
        }

        return false;
}