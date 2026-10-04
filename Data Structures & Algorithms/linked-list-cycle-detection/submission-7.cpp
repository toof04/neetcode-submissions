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
        ListNode* turtle = head;
        ListNode* hare = head;
        while(hare and hare->next){
            turtle=turtle->next;
            hare = hare->next->next;
            if(turtle==hare)return true;
        }
        return false;
    }
};
