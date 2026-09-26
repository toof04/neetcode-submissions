class WordDictionary {
private:
class Node{
public:

    vector<Node*>children;
    bool isend;
    Node(){
        children.resize(26,nullptr);
        isend=false;
    }
};
Node* root;


public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for(char c : word){
            int index = c - 'a';
            if(curr->children[index]==nullptr){
                curr->children[index] = new Node();
            }
            curr = curr->children[index];
        }
        curr->isend=true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(string word, int index, Node* curr){
        if(index==word.size())return curr->isend; 
        char c = word[index];
        //normal chars
        if(c!='.'){
            int i = c - 'a';
            if(curr->children[i]==nullptr)return false;
            return dfs(word, index+1, curr->children[i]);
        }

        //. so check all the indices of the children vector
      for(int i = 0; i < 26;i++){
        if(curr->children[i]!=nullptr and dfs(word,index+1, curr->children[i])){
            return true;
        }
      }
        return false;


    }
};
