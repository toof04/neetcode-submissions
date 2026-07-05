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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode*head  = dummy;
        ListNode*ans = head;
        while(l1 and l2){
            
            int add = l1->val + l2->val + carry;
            if(carry)carry=0;
            carry = add/10;
            add = add%10;
            head->next = new ListNode(add);
            head = head->next;
            l1=l1->next;
            l2=l2->next;
            cout<<"add : "<< add << " carry : "<<carry<<endl;
        }
        while(l1){
               int add = l1->val + carry;
            if(carry)carry=0;
            carry = add/10;
            add = add%10;
            head->next = new ListNode(add);
            head = head->next;
            l1=l1->next;
        }
        while (l2){
            int add = l2->val + carry;
            if(carry)carry=0;
            carry = add/10;
            add = add%10;
            head->next = new ListNode(add);
            head = head->next;
            l2=l2->next; 
        }
        if(carry){
            head->next = new ListNode(carry);
        }
        return ans->next;
        
    }
};
