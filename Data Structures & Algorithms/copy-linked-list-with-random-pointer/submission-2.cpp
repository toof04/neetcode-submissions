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
            if (!head) return nullptr;

        Node* original = head;
        //place copy nodes just after original nodes
        while(original){
           Node* copy = new Node(original->val);
           Node* next = original->next;
           original->next = copy;
           copy->next = next;
           original = copy->next;
        }
        
        //now set random pointers
        original = head;
        while(original){
            if(original->random){
                original->next->random = original->random->next;
               
            }
             original = original->next->next;
        }

        //seperate the two lists
        original = head;
        Node* copyreturner = head->next;
        while(original){
            Node* copy = original->next;
            original->next = copy->next; //making the original list correct as well
            copy->next = copy->next ? copy->next->next : nullptr;
            original = original->next;
        }
        return copyreturner;

    }
};
