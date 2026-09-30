class Solution {
public:
 class Node{
 public:
    vector<Node*>children;
    bool isend;
    Node(){
        children.resize(26, nullptr);
        isend = false;
    }
 };


 class TrieNode{

 public:
     Node* root;

    TrieNode(){
        root = new Node();
    }

    void addword(string word){
        Node* curr = root;
        for(char c : word){
            int index = c - 'a';
            if(curr->children[index]==nullptr){
                curr->children[index] = new Node();
            }
            curr = curr->children[index];
        }
        curr->isend = true;
    }
};


void dfs(vector<vector<char>>&board, int r, int c, Node* node, vector<vector<bool>>& visited, string word, vector<string>& result){
    int rows = board.size();
    int cols = board[0].size();
    if(r < 0 or r >= rows or c < 0 or c>=cols)return;

    if(visited[r][c])return;

    int index = board[r][c] - 'a';
    
    if(node->children[index]==nullptr)return;

    node = node->children[index];

    word+=board[r][c];

    if(node->isend){
        result.push_back(word);
        node->isend = false;
    }

    visited[r][c] = true;

    dfs(board, r - 1, c , node, visited, word, result);
    dfs(board, r + 1, c , node, visited, word, result);
    dfs(board, r , c + 1, node, visited, word, result);
    dfs(board, r , c - 1, node, visited, word, result);

    visited[r][c] = false;
}



    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode  trie;
        for(string word : words){
            trie.addword(word);
        }
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>>visited(rows,vector<bool>(cols,false));
        vector<string>result;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                dfs(board, r, c, trie.root, visited, "", result);
            }
        }
        return result;
    }
};
