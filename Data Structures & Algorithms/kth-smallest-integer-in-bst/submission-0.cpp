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
struct Compare{
    bool operator()(int a, int b){
        return a>b;
    }
};
    void traverse(TreeNode* root, priority_queue<int,vector<int>,Compare> &pq ){
        if(!root)return;
        pq.push(root->val);
        if(root->left)traverse(root->left,pq);
        if(root->right)traverse(root->right,pq);
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int,vector<int>,Compare>pq;
        traverse(root,pq);
        while(--k){
        pq.pop();
        }
        return pq.top();
    }
};
