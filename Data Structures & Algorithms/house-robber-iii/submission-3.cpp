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
    int recurse(TreeNode* node, bool parentChosen){
        if(!node)return 0;
        if(dp.find(node) == dp.end())dp[node] = vector<int>(2,-1);
        if(dp[node][parentChosen] != -1)return dp[node][parentChosen];
        int answer = 0;
        if(parentChosen){
            answer = recurse(node->left,false) + recurse(node->right,false); 
        }
        else{
            //skip
            int skip = recurse(node->left, false) + recurse(node->right, false); 
            //take
            int take = node->val + recurse(node->left, true) + recurse(node->right, true);
            answer = max(skip, take);
        }
        return dp[node][parentChosen] = answer;
    }


    int rob(TreeNode* root) {
        
        return recurse(root,false);
    }
};