// Optimal solution(using slow and fast pointer method)

//leetcode problem 2095

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        if(head==nullptr || head->next==nullptr)
        {
            delete head;
            return nullptr;
        }

        ListNode*slow=head,*fast=head->next->next;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }


        ListNode*node = slow->next;
        slow->next = slow->next->next;

        return head;
        
    }
};

//start with slow = head and fast = slow->next->next and delete node at slow->next