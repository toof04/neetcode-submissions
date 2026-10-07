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
    unordered_map<TreeNode*, vector<int>>dp;
    int recurse(TreeNode* root, bool parentChosen){
        if(!root)return 0;
        if(dp.find(root)==dp.end())dp[root] = vector<int>(2,-1);
        if(dp[root][parentChosen]!=-1)return dp[root][parentChosen];
        int answer = 0;
        if(parentChosen){
            answer = recurse(root->left,false) + recurse(root->right,false);
        }
        else{
            //take
            int take = root->val + recurse(root->left, true) + recurse(root->right, true);
            //skip
            int skip = recurse(root->left, false) + recurse(root->right, false);
            answer = max(take,skip);
        }
        return dp[root][parentChosen] = answer;

    }


    int rob(TreeNode* root) {
        return recurse(root, false);
    }
};