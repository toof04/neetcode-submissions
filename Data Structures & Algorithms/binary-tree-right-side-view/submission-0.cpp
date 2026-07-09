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
    void pushchildren(TreeNode* root, queue<TreeNode*> &s ){
        if (root->left)s.push(root->left);
        if (root->right)s.push(root->right);
       
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>s;
        TreeNode* temp = new TreeNode(-1001);
        if(root){s.push(root);s.push(temp);}
        
        vector<vector<int>>ans;


            while(!s.empty()){
                vector<int>tempvec;
                while(s.front()->val!=-1001){
                    TreeNode* x = s.front();
                    tempvec.push_back(x->val);
                    pushchildren(x,s);
                    s.pop();
                }
                
                s.pop();
                
                ans.push_back(tempvec);
                if(!s.empty())s.push(temp);
            }
        return ans;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>>levelordertrav = levelOrder(root);
        vector<int>ans;
        for(vector<int> level : levelordertrav){
            ans.push_back(level.back());
        }
        return ans;
    }
};
