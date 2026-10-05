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
    int traverse(TreeNode* root, bool &ans){
        if(!root)return 0;
        int l = traverse(root->left, ans);
        int r = traverse(root->right, ans);

        if(abs(l-r)>1)ans = false;
        return 1 + max(l,r);
    }


    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        bool ans = true;
        traverse(root, ans);
        return ans;
    }
};
