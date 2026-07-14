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
    TreeNode* traverse(TreeNode* root, int target){
        if(!root)return nullptr;
       
        root->left=traverse(root->left, target);
        root->right=traverse(root->right, target);
        if(root and !root->left and !root->right and root->val == target){return nullptr;}
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode* head = new TreeNode(0);
        head ->left = root;

        traverse(head, target);
        return head->left;
    }
};