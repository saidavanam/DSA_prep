
// leetcode problem no. 206

/*
Better solution. creating another linked list.

list = [1,2,3,4,5]
operation:-
1 head is 1
2 1 head is 2
3 2 1 head is 3
4 3 2 1 head is 4
5 4 3 2 1 head is 5 

*/

class Solution {
public:
    
    ListNode* reverseList(ListNode* head) {

        ListNode *list = nullptr;

        while(head)
        {
            ListNode *node = new ListNode(head->val);
            if(list==nullptr)
            {
                list = node;
            }
            else
            {
                node->next = list;
                list=node;
            }
            head = head->next;
        }

        return list;

        
        
    }
};


/*
optimal solution:- space complexity is o(1)

creating 2 seperate pointers

core logic :-

        while(head)
        {
            temp = head->next;
            head->next = temp2;
            temp2 = head;
            head = temp;
        }

temp is keeping track of next elements in intial linked lists
temp2 is head of reverse linked lists that we are going to make

at every iteration node -> next is linked to temp2 and temp2 becomes node

*/

class Solution {
public:
    
    ListNode* reverseList(ListNode* head) {

        ListNode *temp=nullptr,*temp2=nullptr;

        while(head)
        {
            temp = head->next;
            head->next = temp2;
            temp2 = head;
            head = temp;
        }

        return temp2;

        
        
    }
};