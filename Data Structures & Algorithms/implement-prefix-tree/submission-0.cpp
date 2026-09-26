class PrefixTree {
private:
 class Node{
 public:
 vector<Node*>children;
 bool isend = false;   
    Node(){
        children.resize(26,nullptr);
    }
 };
Node* root;
public:
    PrefixTree() {             
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        
        for(char c : word){
            int index = c-'a';
            if(curr->children[index]==nullptr){
                curr->children[index] = new Node();
            }
            curr = curr->children[index];
        }
        curr->isend = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for(char c : word){
            int index = c-'a';
            if(curr->children[index]==nullptr)return false;
            curr=curr->children[index];
        }
        return curr->isend;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(char c : prefix){
            int index = c-'a';
            if(curr->children[index]==nullptr)return false;
            curr = curr->children[index];
        }
        return true;
    }
};
