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

    bool check(TreeNode* root, TreeNode* subroot){
        if(!subroot and !root)return true;
        if(!subroot or !root)return false;
        if(subroot->val != root->val)return false;
        
        return check(root->left, subroot->left) and check(root->right, subroot->right);
        
    }

    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(!root and !subroot)return true;
        if(!root or !subroot)return false;
        if(check(root,subroot))return true;
        return isSubtree(root->left, subroot) or isSubtree(root->right, subroot);
    }
};
