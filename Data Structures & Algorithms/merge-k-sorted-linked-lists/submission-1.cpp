/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //ITERATE SABSE CHHOTA DEKHO, NEW LIST MEIN ADD KARO AUR DELETE.
        
       
        ListNode* head = new ListNode(0);
        ListNode* ans = head;
        while(true){
            int empty = 0;
            int smallest = INT_MAX ;
             int indexsmallest = 0;
        for(int i = 0; i < lists.size(); i++){
            if(!lists[i]){empty++;continue;}   
            if (smallest>=lists[i]->val){
                smallest = lists[i]->val;
                indexsmallest = i;
            }
        }

        if(empty==lists.size())break;

                head->next = new ListNode(lists[indexsmallest]->val);
        ListNode* temp = lists[indexsmallest];
        lists[indexsmallest]= lists[indexsmallest]->next;
        delete temp;
        head = head ->next;

        }

        return ans->next;

    }
};
