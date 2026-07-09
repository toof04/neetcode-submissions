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
    void dfs (TreeNode* root, int &ans, int maxinpath){
        if(!root)return;
        
        if(root->val >= maxinpath){cout<<root->val<<" ";ans++;}
        maxinpath = max(maxinpath, root->val);
        if(root->left)dfs(root->left, ans, maxinpath);
        if(root->right)dfs(root->right, ans, maxinpath);
    }
    int goodNodes(TreeNode* root) {
        int ans = 0;
        //if(root)ans++;
         dfs(root, ans, -101);
        return ans;
    }
};
