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
    void dfs(TreeNode* root, TreeNode* parent, int val){
        if(!root) {
            TreeNode* newnode = new TreeNode(val);
            if(val < parent->val)parent->left =newnode;
            else parent->right = newnode;
            return;
        }
        if(root->val > val)dfs(root->left,root,val);
        if (root->val < val)dfs(root->right,root, val);
        return;

    }


    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)return new TreeNode(val);
        dfs(root,root, val);
        return root;
    }
};