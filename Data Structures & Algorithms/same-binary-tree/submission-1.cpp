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
    void trav(TreeNode*p, TreeNode*q, bool &ans){
         if(!p and !q)return;
        if(!p and q){ans=false;return;}
        if(p and !q){ans=false;return;}
       
        if(p->val != q->val){ans=false;return;}
        trav(p->left,q->left,ans);
        trav(p->right,q->right,ans);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p and !q) return true;
        if(!p or !q) return false;

        bool ans = true;
        trav(p,q,ans);
        
        return ans;
    }
};
