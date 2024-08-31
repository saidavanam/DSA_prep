 // leetcode problem 61

 /*
    do rotations when K>0. right rotations by k places is left rotations by n-k places.
 */

 class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        ListNode *ptr = head;

        if(head==nullptr) //if list is empty
        {
            return nullptr;
        }

        int length = 0;

        while(ptr!=nullptr) //finding length of LL
        {
            length++;
            ptr = ptr->next;
        }

        ptr = head;

        int rotations = k % length; //finding rotations 

        if(rotations) // performing rotation when rotations >0
        {
            for(int i=0;i<length-rotations-1;i++)
            {
                ptr = ptr->next;
            }

            ListNode *newhead = ptr->next;
            ptr->next = nullptr;
            ListNode *ptr2 = newhead;  

            while(ptr2->next!=nullptr)
           {
              ptr2 = ptr2->next;
           }
           ptr2->next = head;

           return newhead; //return head of kth node from last          

        }
        
        return head; //return the head if no rotation
        
    }
};