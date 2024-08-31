// leetcode problem no. 234

/*
using slow and fast pointer
1)when odd no. of nodes are there then slow is at middle node, nodes from slow->next is reversed and then compared first half and second half.
2)when even no. of nodes are there then slow is at n/2 position, same process as of 1)
*/

class Solution {
public:
    ListNode * reverse(ListNode *ptr)
    {
        ListNode * temp_1 = nullptr, *temp_2 = nullptr;

        while(ptr != nullptr)
        {
            temp_1 = ptr->next;
            ptr->next = temp_2;
            temp_2 = ptr;
            ptr = temp_1;
        }
        return temp_2;
    }
    bool isPalindrome(ListNode* head) {

        ListNode* slow = head, *fast = head;

        while(fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

       ListNode * newhead = reverse(slow->next);

        ListNode * temp1 = head;
        ListNode * temp2 = newhead;

        while(temp2 != nullptr)
        {
            if(temp1->val!=temp2->val)
            {
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return true;


        
    }
};