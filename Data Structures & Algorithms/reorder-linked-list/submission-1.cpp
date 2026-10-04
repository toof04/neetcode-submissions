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
    ListNode* reverse(ListNode*head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* first = head;
        ListNode* second = head;
        while(second and second->next){
            first = first->next;
            second = second->next->next;
        }        
        ListNode* secondhalf = reverse(first->next);
        first->next = nullptr;
        
        first = head;
        while(secondhalf){
            ListNode* t1 = first->next;
            ListNode* t2 = secondhalf->next;
            first->next = secondhalf;
            secondhalf->next = t1;
            first = t1;
            secondhalf = t2;
        }
        
    }
};
