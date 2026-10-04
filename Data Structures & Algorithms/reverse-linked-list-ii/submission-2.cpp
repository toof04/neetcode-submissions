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


    void reverse(ListNode* curr, int left, int right){
        ListNode* before = curr;
        ListNode* prev = nullptr;
         curr = curr->next;
         ListNode* first = curr;
        ListNode* next;
        int count = right - left + 1;
        while(curr and count--){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        before->next = prev;
        first->next = curr;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = dummy;
        int pos = 1;
        while(curr->next){
            if(left  == pos){
                reverse(curr, left, right);
                break;
            }
            curr=curr->next;
            pos++;

        }
        return dummy->next;

    }
};