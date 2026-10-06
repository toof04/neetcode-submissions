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
class Solution {
public:
    TreeNode* dfs(TreeNode* root, int key){
        if(!root)return nullptr;
        if(root->val > key)root->left = dfs(root->left, key);
        else if(root->val < key)root -> right = dfs(root->right, key);
        else {
            if(!root->left)return root->right;
            else if(!root->right)return root->left;
            else{
                TreeNode* succ = root->right;
                while(succ->left)succ=succ->left;
                root->val = succ->val;
                root->right = dfs(root->right, succ->val);
            }
        }
        return root;
    }


    TreeNode* deleteNode(TreeNode* root, int key) {
        root = dfs(root, key);
        return root;
    }
};