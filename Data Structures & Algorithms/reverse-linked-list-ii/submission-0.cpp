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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int i = 1;
        ListNode* ans = head;
        ListNode* prev = nullptr, *next;
        while(head){
            if(i+1 == left){
                prev = head;    
            }
            if(i==left){
                break;
            }
            i++;
            head=head->next;
        }
        ListNode* firststitch = prev;
         
       ListNode* start = head;

       ListNode* curr = head;
    prev = nullptr;

        while(curr and i<=right){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            i++;
        }
        if(firststitch)firststitch->next = prev;
        else ans = prev;
        start->next = curr;

        return ans;


    }
};