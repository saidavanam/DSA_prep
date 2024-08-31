// Leetcode problem 160

/*
  At first we are traversing the LL which has more nodes until it reaches diff length and then we traverse both lists at a time. if they point to same node,
  then return that node else nullptr.
*/


class Solution {
public:
    ListNode* traverse(ListNode *ptr1,ListNode *ptr2,int diff)
    {
        int count = 0;
        while(count<diff)
        {
            count++;
            ptr1 = ptr1->next;
        }

        while(ptr1 !=nullptr)
        {
            if(ptr1==ptr2)
            {
                return ptr1;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        return nullptr;

    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int count_A = 0,count_B = 0;

        ListNode *ptr1 = headA, *ptr2 = headB , *ans;

        while(ptr1 != nullptr)
        {
            ptr1 = ptr1->next;
            count_A++;
        }
        
        while(ptr2 != nullptr)
        {
            ptr2 = ptr2->next;
            count_B++;
        }

        int diff = abs(count_A-count_B);

        if(count_A>=count_B)
        {
            ans = traverse(headA,headB,diff);
        }
        else
        {
            ans = traverse(headB,headA,diff);
        }

        return ans;
        
    }
};