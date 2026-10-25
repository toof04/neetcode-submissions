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
    pair<ListNode*, ListNode*>reverse(ListNode* start, ListNode* end){
        ListNode* first = end;
        ListNode* last = start;
        ListNode* curr = start;
        ListNode* prev = nullptr;
        while(prev!=end){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr=next;
        }
        return {first,last};
    }//Logic looks correct, so remove the stray // on line 26 and run or submit.

    ListNode* reverseKGroup(ListNode* head, int k) {
        int length = 0;
        ListNode* temp = head;
        while(temp){
            length++;
            temp=temp->next;
        }

        int times = length/k;
                ListNode* dummy = new ListNode(0,head);

        ListNode* start = head;
        ListNode* end = head;
        int currlen = 1;
        ListNode* previous = dummy;
        for(int i = 0; i < times;i++){
            while(currlen<k){
                currlen++;
                end = end->next;
            }
            ListNode* nextEnd = end->next;
            pair<ListNode*,ListNode*>connecter = reverse(start,end);
            previous->next = connecter.first;
            connecter.second->next = nextEnd;
            currlen = 1;
            previous = start;
            start = nextEnd;
            end = nextEnd;
        }
        return dummy->next;
  
    }
};
