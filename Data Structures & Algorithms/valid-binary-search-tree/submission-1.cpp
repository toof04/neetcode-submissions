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
    void dfs(TreeNode* root, pair<int,int>interval, bool &ans){
        if(!(interval.first < root->val and interval.second > root->val)){
            ans = false;
            return;
        }
        
        if(root->left){
            int left = interval.first;
            int right = root->val;
            dfs(root->left,{left, right}, ans);
        }
        if(root->right){
            int right = interval.second;
            int left = root->val;
            
            dfs(root->right, {left, right}, ans);
        }
    }
    bool isValidBST(TreeNode* root) {
        pair<int,int>interval = {-1001, 1001};
        bool ans = true;
        dfs(root,interval,ans);
        return ans;
    }
};
