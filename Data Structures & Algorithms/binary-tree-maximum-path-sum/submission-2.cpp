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
int maximum = INT_MIN;

    int recurse(TreeNode* root){
        if(!root)return 0;

        int left = max(0, recurse(root->left));
        int right = max(0, recurse(root->right));

        int currect = left + right + root->val;
        maximum = max(maximum, currect);
        return root->val + max(left, right);
    }


    int maxPathSum(TreeNode* root) {
        recurse(root);
        return maximum;
    }
};
