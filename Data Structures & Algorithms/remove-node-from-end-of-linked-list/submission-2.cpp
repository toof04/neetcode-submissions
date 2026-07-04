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
    ListNode* removeNthFromEnd(ListNode* head, int e) {
        if(!head)return head;
        if(!head->next and e == 1 )return nullptr;
        int n = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            n++;
            }
        if( e == n){
            ListNode* newhead = head->next;
            return newhead;
        }
        n = n - e - 1;
        ListNode* ans= head;
        while(head->next and n--){
            head=head->next;
        }
        cout<<"removing : "<< head->val <<" from position : "<<n<<endl;
        
        if(head->next){
            ListNode* prev = head;
            ListNode* forward = head->next->next;
            prev->next = forward;
        }

        return ans;


    }
};
