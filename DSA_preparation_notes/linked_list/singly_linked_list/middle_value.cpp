//leetcode problem no. 876

//optimal solution using slow and fast pointer

class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        ListNode* slow=head,*fast=head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
       
    }
};