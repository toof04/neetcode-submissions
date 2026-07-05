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

struct compare{
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare>pq;
        for(auto i : lists){
            if(i)pq.push(i);
            }
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;

        while(!pq.empty()){
            ListNode* curr = pq.top();
            pq.pop();

            head->next = curr;
            head = head->next;
            if(curr->next)pq.push(curr->next);

        }
        return dummy->next;
    }
};
