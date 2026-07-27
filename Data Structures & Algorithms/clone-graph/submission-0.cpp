/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
unordered_map<Node*, Node*> cloned;
class Solution {
public:
    Node* make(Node* oldnode){
        if(!oldnode)return nullptr;
            if(cloned.count(oldnode))return cloned[oldnode];
         Node* create = new Node(oldnode->val);
         cloned[oldnode] = create;
        for(int i = 0 ; i < oldnode->neighbors.size(); i++){
            create->neighbors.push_back(make(oldnode->neighbors[i]));
        }
        return create;
    }

    Node* cloneGraph(Node* node) {
        
        Node* head = make(node);
        return head;
    }
};
