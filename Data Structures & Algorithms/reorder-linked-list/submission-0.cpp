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
    ListNode* reverse(ListNode* temp){
        ListNode* prev, *curr, *next;
        prev = nullptr;
        curr = temp;

        while(curr){
            next = curr->next;
            curr->next = prev;
             prev = curr;
            curr = next;
           
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* temp = head;
        ListNode* half = head; //fast
        ListNode* mid = head; //slow
        while(half->next and half->next->next){
            mid = mid->next;
            half = half->next->next;
        }
        half = mid->next;
        mid->next = nullptr;
       
        ListNode* second = reverse(half);
        ListNode* first = head;
        while(second){
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;
            first->next = second;
            second->next = t1;

            first = t1;
            second = t2;
        }
        

    }
};
