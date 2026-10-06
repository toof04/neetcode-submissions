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
    void dfs(TreeNode* root, pair<int,int> interval, bool &ans){
        if(!root)return;
        if(!(interval.first < root->val and root->val < interval.second)){
            ans = false;
            return;
        }
        if(root->left){
            dfs(root->left,{interval.first,root->val},ans);
        }
        if(root->right){
            dfs(root->right,{root->val,interval.second}, ans);
        }
    }


    bool isValidBST(TreeNode* root) {
        pair<int,int>interval = {INT_MIN, INT_MAX};
        bool ans = true;
        dfs(root, interval, ans);
        return ans;
    }
};
