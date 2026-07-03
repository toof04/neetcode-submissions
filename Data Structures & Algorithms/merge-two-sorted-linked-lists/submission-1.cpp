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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)return list2;
        if(!list2)return list1;
        ListNode* ans;
        ListNode* help = new ListNode(0);
        ListNode* temp = help;
        while(list1 and list2){
        if(list1->val >= list2->val){
           help->next  = new ListNode(list2->val);
          list2= list2->next;
          help=help->next;
        } 
        else{ help->next = new ListNode(list1->val);
       list1= list1->next;help=help->next;}
        }
        if(list1){
       
                help->next = list1;
 
            
        }
        if(list2){
           
                help->next = list2;
            
        }


        return temp->next;
    }
};
