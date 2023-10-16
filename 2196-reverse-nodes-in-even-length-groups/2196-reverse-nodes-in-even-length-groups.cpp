
class Solution {
public:


void swap(ListNode* A, ListNode* B)
{
    int tmp = A->val;
    A->val = B->val;
    B->val = tmp;
}

void reverse_node(vector<ListNode*> &arr)
{
    int i = 0, j = arr.size()-1;

    while(i<=j) swap(arr[i++], arr[j--]);
    
}


    ListNode* reverseEvenLengthGroups(ListNode* head) {
        
        vector<ListNode*>res;
        int i = 1;
        int cnt = 0;
        
        ListNode *ptr = head;

        while(ptr != NULL)
        {
           
           res.push_back(ptr);
           ptr = ptr->next;
           cnt++;

           if(cnt == i)
           {
               if(cnt % 2 == 0) reverse_node(res);
               res.clear();
               cnt = 0;
               i++;
           }

        }

        if(cnt%2 == 0) reverse_node(res);


        return head;

    }
};
