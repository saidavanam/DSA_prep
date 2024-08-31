// leetcode problem 148

/*
using extra space n for storing elements in an array and applying merge sort to it and writing back to linked list

space complexity is o(n)
Time complexity is o(nlogn)+o(n)+o(n)

*/

class Solution {
public:
    void merge(vector<int>&arr,int lb,int mid,int ub)
    {
        vector<int> dup;
        int i = lb, j = mid+1;

        while(i<=mid && j<=ub)
        {
            if(arr[i]>=arr[j])
            {
                dup.push_back(arr[j]);
                j++;
            }
            else
            {
                dup.push_back(arr[i]);
                i++;
            }
        }

        while(i<=mid)
        {
            dup.push_back(arr[i]);
            i++;
        }
        while(j<=ub)
        {
            dup.push_back(arr[j]);
            j++;
        }

        for(int z=0;z<dup.size();z++)
        {
            arr[z+lb] = dup[z];
        }
    }
    void mergesort(vector<int> &arr,int lb,int ub)
    {
        if(lb<ub)
        {
            int mid = (lb+ub)/2;
            mergesort(arr,lb,mid);
            mergesort(arr,mid+1,ub);
            merge(arr,lb,mid,ub);
        }
    }
    ListNode* sortList(ListNode* head) {

        ListNode *temp = head;
        vector<int> arr;

        while(temp!=nullptr)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        mergesort(arr,0,arr.size()-1);
        temp = head;

        for(int i=0;i<arr.size();i++)
        {
            temp->val = arr[i];
            temp = temp->next;

        }

        return head;


        
    }
};


/*
Optimal solution without extra space. explanation in the notes.
*/

class Solution {
public:
    ListNode *find_middle(ListNode* head)
    {
        ListNode *slow = head, *fast = head->next;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    ListNode *merge(ListNode*list1,ListNode*list2)
    {
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;

        while(list1!=nullptr && list2!=nullptr)
        {
            if(list1->val < list2->val)
            {
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }

        if(list1)
        {
            temp->next = list1;
            temp = list1;
            list1 = list1->next;

        }
        if(list2)
        {
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }

        return dummy->next;
    }

    ListNode *mergesort(ListNode*head)
    {
        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }

        ListNode *middle = find_middle(head);
        ListNode *right = middle->next;
        middle->next = nullptr;
        ListNode *left = head;

        left = mergesort(left);
        right = mergesort(right);

        return merge(left,right);
    }
    ListNode* sortList(ListNode* head) {

        return mergesort(head);

        
    }
};

/*
time complexity is o((n+n/2)logn) and space complexity is o(1)
*/