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

    TreeNode* traverse(TreeNode* root, int rarget){
        if(!root)return nullptr;
        root->left = traverse(root->left, rarget);
        root->right = traverse(root->right,rarget);
        if(root and root->left == nullptr and root->right == nullptr and root->val == rarget){
            delete root;
            return nullptr;
        }
        return root;
    }



    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode* toproot = new TreeNode(0);
        toproot->left = root;
        traverse(toproot, target);
        return toproot->left;
    }
};