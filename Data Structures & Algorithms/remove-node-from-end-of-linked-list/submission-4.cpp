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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* fast = head;
        ListNode* slow = new ListNode(0);
        ListNode* answer = slow;
        slow->next = head;
        //placing slow one behind because we'll use its previous for linking

        int i = 0;
        while(fast and i<n){
            fast=fast->next;
            i++;
        }
        //now fast is at the nth place

        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        //now slow is exactly at Nth node from the end
        slow->next = slow->next->next;

        return answer->next;

    }
};
