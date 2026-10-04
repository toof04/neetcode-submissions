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
struct Compare{
    bool operator()(ListNode* a, ListNode* b){
         return a->val> b->val;
    }
};



    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, Compare>pq;
        for(auto i : lists){
            if(i)pq.push(i);
        }
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(!pq.empty()){
            ListNode* top = pq.top();
            pq.pop();
            curr->next = top;
            curr = curr->next;
            top = top->next;
            if(top){
                pq.push(top);
            }
        }
        return dummy->next;
    }
};
