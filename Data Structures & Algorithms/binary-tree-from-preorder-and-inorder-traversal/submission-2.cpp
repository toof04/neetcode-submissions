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
    int searchInorder(vector<int>&inorder, int preIdx, int left, int right){
        for(int i = left; i<=right; i++){
            if(preIdx == inorder[i])return i;
        }
        cout<<"returning -1";
        return -1;
    }
    TreeNode* helper(vector<int>&preorder, vector<int>&inorder, int &preIdx, int left, int right){
        if (left > right)return NULL;
        TreeNode* root = new TreeNode(preorder[preIdx]);
        
        int inorderIdx = searchInorder(inorder,preorder[preIdx], left, right);
        preIdx++;
        root->left = helper(preorder,inorder,preIdx, left, inorderIdx-1);
        root->right = helper(preorder,inorder,preIdx,inorderIdx+1,right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int p = 0;
        return helper(preorder, inorder, p , 0,preorder.size()-1);

    }
};
