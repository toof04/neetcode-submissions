/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       if(!head)return nullptr;
       Node* curr = head;
       while(curr){
        Node* copy = new Node(curr->val);
        copy->next = curr->next;
        curr->next = copy;
        curr = copy->next;
       } 
        curr = head;
        while(curr){
            if(curr->random)curr->next->random = curr->random->next;

            curr=curr->next->next;
        }
        curr = head;

        Node* copyhead = head->next;
        Node*copycurr = copyhead;

        while(curr){
            curr->next = curr->next->next;
            if(copycurr->next){
                copycurr->next=copycurr->next->next;
            }
            curr=curr->next;
            copycurr = copycurr->next;
        }
        return copyhead;

    }
};
