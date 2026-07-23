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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* root = head;
        while(root and root->next){
            ListNode* oldnext = root->next;
            int val = gcd(root->val, oldnext->val);
            ListNode* insert = new ListNode(val);
            root->next = insert;
            insert -> next = oldnext;
            root = oldnext;
        }
        return head;
    }
};