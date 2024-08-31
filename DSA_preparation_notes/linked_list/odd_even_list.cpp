
//leetcode problem 328

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }

        ListNode *odd = head,*odd_head=odd,*even=head->next,*even_head=even;

        while(even!=nullptr && even->next!=nullptr)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }

        odd->next = even_head;

        return head;

        
    }
};

// segeregating odd and even and adding even to odd at last