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
    bool hasCycle(ListNode* head) {
        ListNode* hare = head;
        ListNode* turtle = head;
        while(hare and turtle and hare->next and hare->next->next and turtle->next){
            hare=hare->next->next;
            turtle=turtle->next;
            if(hare==turtle){
                return true;
            }
        }
        return false;
    }
};
