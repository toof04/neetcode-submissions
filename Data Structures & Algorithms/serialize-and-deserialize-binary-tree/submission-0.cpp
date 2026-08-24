/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
private:
    vector<string>splitString;
    string data = "";
    int index;
    void serializeDFS(TreeNode* root){
        if(!root){data+="null,";return;}
        data+=(to_string(root->val)+",");
        serializeDFS(root->left);
        serializeDFS(root->right);
    }

    void splitData(string data){
        splitString.clear();
        string token;
        stringstream ss(data);
        while(getline(ss,token,',')){
            splitString.push_back(token);
        }
    }
    TreeNode* deserializeDFS(){
        string token = splitString[index++];
        if(token == "null"){
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(token));
        node->left = deserializeDFS();
        node->right = deserializeDFS();
        return node;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        serializeDFS(root);
        return data;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
         splitData(data);
         index = 0;
         return deserializeDFS();
    }
};
