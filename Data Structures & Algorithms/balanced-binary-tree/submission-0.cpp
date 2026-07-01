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
    int trav(TreeNode* root, bool &ans){
        if(!root)return 0;
        int lh =  trav(root->left,ans);
        int rh =  trav(root->right,ans);
        cout<<root->val<<" l:"<<lh<<" r:"<<rh<<endl;
        if(abs(lh-rh)>1)ans = false;
        return 1 + max(lh,rh);
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        bool ans = true;
        trav(root,ans);
        return ans;
    }
};
